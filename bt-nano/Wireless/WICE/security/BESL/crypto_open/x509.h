/*
 * Copyright 2015, Broadcom Corporation
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Broadcom Corporation;
 * the contents of this file may not be disclosed to third parties, copied
 * or duplicated in any form, in whole or in part, without the prior
 * written permission of Broadcom Corporation.
 */

/* Originally taken from TropicSSL
 * https://gitorious.org/tropicssl/
 * commit: 92bb3462dfbdb4568c92be19e8904129a17b1eed
 * Whitespace converted (Tab to 4 spaces, LF to CRLF)
 * int arguments/returns changed to int32_t
 * add option for generalized time
 * add const to arguments where appropriate
 * remove x509parse_crtfile, x509parse_crtfile and x509parse_keyfile
 * add function x509parse_pubkey() to parse a public rsa key
 */

/**
 * \file x509.h
 *
 *  Based on XySSL: Copyright (C) 2006-2008  Christophe Devine
 *
 *  Copyright (C) 2009  Paul Bakker <polarssl_maintainer at polarssl dot org>
 *
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *    * Neither the names of PolarSSL or XySSL nor the names of its contributors
 *      may be used to endorse or promote products derived from this software
 *      without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 *  TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 *  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 *  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 *  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef TROPICSSL_X509_H
#define TROPICSSL_X509_H

#include "wiced_security.h"

#define TROPICSSL_ERR_ASN1_OUT_OF_DATA                      -0x0014
#define TROPICSSL_ERR_ASN1_UNEXPECTED_TAG                   -0x0016
#define TROPICSSL_ERR_ASN1_INVALID_LENGTH                   -0x0018
#define TROPICSSL_ERR_ASN1_LENGTH_MISMATCH                  -0x001A
#define TROPICSSL_ERR_ASN1_INVALID_DATA                     -0x001C

#define TROPICSSL_ERR_X509_FEATURE_UNAVAILABLE              -0x0020
#define TROPICSSL_ERR_X509_CERT_INVALID_PEM                 -0x0040
#define TROPICSSL_ERR_X509_CERT_INVALID_FORMAT              -0x0060
#define TROPICSSL_ERR_X509_CERT_INVALID_VERSION             -0x0080
#define TROPICSSL_ERR_X509_CERT_INVALID_SERIAL              -0x00A0
#define TROPICSSL_ERR_X509_CERT_INVALID_ALG                 -0x00C0
#define TROPICSSL_ERR_X509_CERT_INVALID_NAME                -0x00E0
#define TROPICSSL_ERR_X509_CERT_INVALID_DATE                -0x0100
#define TROPICSSL_ERR_X509_CERT_INVALID_PUBKEY              -0x0120
#define TROPICSSL_ERR_X509_CERT_INVALID_SIGNATURE           -0x0140
#define TROPICSSL_ERR_X509_CERT_INVALID_EXTENSIONS          -0x0160
#define TROPICSSL_ERR_X509_CERT_UNKNOWN_VERSION             -0x0180
#define TROPICSSL_ERR_X509_CERT_UNKNOWN_SIG_ALG             -0x01A0
#define TROPICSSL_ERR_X509_CERT_UNKNOWN_PK_ALG              -0x01C0
#define TROPICSSL_ERR_X509_CERT_SIG_MISMATCH                -0x01E0
#define TROPICSSL_ERR_X509_CERT_VERIFY_FAILED               -0x0200
#define TROPICSSL_ERR_X509_KEY_INVALID_PEM                  -0x0220
#define TROPICSSL_ERR_X509_KEY_INVALID_VERSION              -0x0240
#define TROPICSSL_ERR_X509_KEY_INVALID_FORMAT               -0x0260
#define TROPICSSL_ERR_X509_KEY_INVALID_ENC_IV               -0x0280
#define TROPICSSL_ERR_X509_KEY_UNKNOWN_ENC_ALG              -0x02A0
#define TROPICSSL_ERR_X509_KEY_PASSWORD_REQUIRED            -0x02C0
#define TROPICSSL_ERR_X509_KEY_PASSWORD_MISMATCH            -0x02E0
#define TROPICSSL_ERR_X509_POINT_ERROR                      -0x0300
#define TROPICSSL_ERR_X509_VALUE_TO_LENGTH                  -0x0320

#define BADCERT_EXPIRED                 1
#define BADCERT_REVOKED                 2
#define BADCERT_CN_MISMATCH             4
#define BADCERT_NOT_TRUSTED             8

/*
 * DER constants
 */
#define ASN1_BOOLEAN                 0x01
#define ASN1_INTEGER                 0x02
#define ASN1_BIT_STRING              0x03
#define ASN1_OCTET_STRING            0x04
#define ASN1_NULL                    0x05
#define ASN1_OID                     0x06
#define ASN1_UTF8_STRING             0x0C
#define ASN1_SEQUENCE                0x10
#define ASN1_SET                     0x11
#define ASN1_PRINTABLE_STRING        0x13
#define ASN1_T61_STRING              0x14
#define ASN1_IA5_STRING              0x16
#define ASN1_UTC_TIME                0x17
#define ASN1_GENERALISED_TIME        0x18
#define ASN1_UNIVERSAL_STRING        0x1C
#define ASN1_BMP_STRING              0x1E
#define ASN1_PRIMITIVE               0x00
#define ASN1_CONSTRUCTED             0x20
#define ASN1_CONTEXT_SPECIFIC        0x80

/*
 * various object identifiers
 */
#define X520_COMMON_NAME                3
#define X520_COUNTRY                    6
#define X520_LOCALITY                   7
#define X520_STATE                      8
#define X520_ORGANIZATION              10
#define X520_ORG_UNIT                  11
#define PKCS9_EMAIL                     1

#define X509_OUTPUT_DER              0x01
#define X509_OUTPUT_PEM              0x02
#define PEM_LINE_LENGTH                72
#define X509_ISSUER                  0x01
#define X509_SUBJECT                 0x02

#define OID_X520                "\x55\x04"
#define OID_CN                  "\x55\x04\x03"
#define OID_PKCS1               "\x2A\x86\x48\x86\xF7\x0D\x01\x01"
#define OID_PKCS1_RSA           "\x2A\x86\x48\x86\xF7\x0D\x01\x01\x01"
#define OID_PKCS1_RSA_SHA       "\x2A\x86\x48\x86\xF7\x0D\x01\x01\x05"
#define OID_PKCS9               "\x2A\x86\x48\x86\xF7\x0D\x01\x09"
#define OID_PKCS9_EMAIL         "\x2A\x86\x48\x86\xF7\x0D\x01\x09\x01"

/*
 * Structures for parsing X.509 certificates
 */
/* Prevent redefinition of types from crypto_structures.h */
#ifndef CRYPTO_STRUCTURE
typedef struct _x509_buf {
    int32_t tag;
    int32_t len;
    const unsigned char *p;
} x509_buf;

typedef struct _x509_name {
    x509_buf oid;
    x509_buf val;
    struct _x509_name *next;
} x509_name;

typedef struct _x509_time {
        uint16_t year;
        uint8_t  mon;
        uint8_t  day;
        uint8_t  hour;
        uint8_t  min;
        uint8_t  sec;
} x509_time;

typedef struct _x509_cert {
    x509_buf raw;
    x509_buf tbs;

    int32_t version;
    x509_buf serial;
    x509_buf sig_oid1;

    x509_buf issuer_raw;
    x509_buf subject_raw;

    x509_name issuer;
    x509_name subject;

    x509_time valid_from;
    x509_time valid_to;

    x509_buf pk_oid;
    rsa_context rsa;

    x509_buf issuer_id;
    x509_buf subject_id;
    x509_buf v3_ext;

    int32_t ca_istrue;
    int32_t max_pathlen;

    x509_buf sig_oid2;
    x509_buf sig;

    struct _x509_cert *next;
} x509_cert;

/*
 * Structures for writing X.509 certificates
 */
typedef struct _x509_node {
    unsigned char *data;
    unsigned char *p;
    unsigned char *end;

    uint32_t len;
} x509_node;

typedef struct _x509_raw {
    x509_node raw;
    x509_node tbs;

    x509_node version;
    x509_node serial;
    x509_node tbs_signalg;
    x509_node issuer;
    x509_node validity;
    x509_node subject;
    x509_node subpubkey;

    x509_node signalg;
    x509_node sign;
} x509_raw;
#endif

#ifdef __cplusplus
extern "C" {
#endif

    /**
     * \brief          Parse one or more certificates and add them
     *                 to the chained list
     *
     * \param chain    points to the start of the chain
     * \param buf      buffer holding the certificate data
     * \param buflen   size of the buffer
     *
     * \return         0 if successful, or a specific X509 error code
     */
    int32_t x509parse_crt(x509_cert *chain, const unsigned char *buf, uint32_t buflen);

    /**
     * \brief          Load one or more certificates and add them
     *                 to the chained list
     *
     * \param chain    points to the start of the chain
     * \param path     filename to read the certificates from
     *
     * \return         0 if successful, or a specific X509 error code
     */
    int32_t x509parse_crtfile(x509_cert *chain, const char *path);

    /**
     * \brief          Parse a public RSA key
     *
     * \param rsa      RSA context to be initialized
     * \param buf      input buffer
     * \param buflen   size of the buffer
     * \param pwd      password for decryption (optional)
     * \param pwdlen   size of the password
     *
     * \return         0 if successful, or a specific X509 error code
     */
    int32_t x509parse_pubkey(rsa_context *rsa,
                       unsigned char *key, int32_t keylen,
                       unsigned char *pwd, int32_t pwdlen);


    /**
     * \brief          Parse a private RSA key
     *
     * \param rsa      RSA context to be initialized
     * \param key      input buffer
     * \param keylen   size of the buffer
     * \param pwd      password for decryption (optional)
     * \param pwdlen   size of the password
     *
     * \return         0 if successful, or a specific X509 error code
     */
    int32_t x509parse_key(rsa_context *rsa,
              const unsigned char *key, uint32_t keylen,
              const unsigned char *pwd, uint32_t pwdlen);

    /**
     * \brief          Load and parse a private RSA key
     *
     * \param rsa      RSA context to be initialized
     * \param path     filename to read the private key from
     * \param pwd      password to decrypt the file (can be NULL)
     *
     * \return         0 if successful, or a specific X509 error code
     */
    int32_t x509parse_keyfile(rsa_context *rsa, const char *path, const char *password);

    /**
     * \brief          Store the certificate DN in printable form into buf;
     *                 no more than (end - buf) characters will be written.
     */
    int32_t x509parse_dn_gets( char *buf, const char *end, const x509_name *dn );

    /**
     * \brief          Returns an informational string about the
     *                 certificate.
     */
    char *x509parse_cert_info(char *buf, size_t buf_size, const char *prefix, const x509_cert * crt);
    /**
     * \brief          Return 0 if the certificate is still valid,
     *                 or BADCERT_EXPIRED
     */
    int32_t x509parse_expired(const x509_cert *crt);

    /**
     * \brief          Verify the certificate signature
     *
     * \param crt      a certificate to be verified
     * \param trust_ca the trusted CA chain
     * \param cn       expected Common Name (can be set to
     *                 NULL if the CN must not be verified)
     * \param flags    result of the verification
     *
     * \return         0 if successful or TROPICSSL_ERR_X509_SIG_VERIFY_FAILED,
     *                 in which case *flags will have one or more of
     *                 the following values set:
     *                      BADCERT_EXPIRED --
     *                      BADCERT_REVOKED --
     *                      BADCERT_CN_MISMATCH --
     *                      BADCERT_NOT_TRUSTED
     *
     * \note           TODO: add two arguments, depth and crl
     */
    int32_t x509parse_verify(const x509_cert *crt,
                 const x509_cert *trust_ca,
                 const char *cn, int32_t *flags);

    /**
     * \brief          Unallocate all certificate data
     */
    void x509_free(x509_cert * crt);

    /**
     * \brief          Checkup routine
     *
     * \return         0 if successful, or 1 if the test failed
     */
    int32_t x509_self_test(int32_t verbose);

#ifdef __cplusplus
}
#endif

#endif /* x509.h */
