/*
 * ModSecurity, http://www.modsecurity.org/
 * Copyright (c) 2015 Trustwave Holdings, Inc. (http://www.trustwave.com/)
 *
 * You may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * If any of the files related to licensing are missing or if you have any
 * other questions related to licensing please contact Trustwave Holdings, Inc.
 * directly using the email address security@modsecurity.org.
 *
 */


#include <string.h>

#include "modsecurity/modsecurity.h"
#include "actions/transformations/transformation.h"

/**
 * for i in $(ls -l *h | awk {'print $9'}); do echo "#include \"actions/transformations/$i\""; done;
 *
 */
#include "actions/transformations/base64_decode_ext.h"
#include "actions/transformations/base64_decode.h"
#include "actions/transformations/cmd_line.h"
#include "actions/transformations/compress_whitespace.h"
#include "actions/transformations/css_decode.h"
#include "actions/transformations/escape_seq_decode.h"
#include "actions/transformations/hex_decode.h"
#include "actions/transformations/hex_encode.h"
#include "actions/transformations/html_entity_decode.h"
#include "actions/transformations/js_decode.h"
#include "actions/transformations/length.h"
#include "actions/transformations/lower_case.h"
#include "actions/transformations/md5.h"
#include "actions/transformations/none.h"
#include "actions/transformations/normalise_path.h"
#include "actions/transformations/normalise_path_win.h"
#include "actions/transformations/parity_even_7bit.h"
#include "actions/transformations/parity_odd_7bit.h"
#include "actions/transformations/parity_zero_7bit.h"
#include "actions/transformations/remove_comments_char.h"
#include "actions/transformations/remove_comments.h"
#include "actions/transformations/remove_nulls.h"
#include "actions/transformations/remove_whitespace.h"
#include "actions/transformations/replace_comments.h"
#include "actions/transformations/replace_nulls.h"
#include "actions/transformations/sha1.h"
#include "actions/transformations/sql_hex_decode.h"
#include "actions/transformations/transformation.h"
#include "actions/transformations/trim.h"
#include "actions/transformations/trim_left.h"
#include "actions/transformations/trim_right.h"
#include "actions/transformations/url_decode.h"
#include "actions/transformations/url_decode_uni.h"
#include "actions/transformations/url_encode.h"
#include "actions/transformations/utf8_to_unicode.h"


/**
 * for i in $(ls -l *h | awk {'print $9'}); do echo "#include \"operators/$i\""; done;
 *
 */
#include "operators/begins_with.h"
#include "operators/contains.h"
#include "operators/contains_word.h"
#include "operators/detect_sqli.h"
#include "operators/detect_xss.h"
#include "operators/ends_with.h"
#include "operators/eq.h"
#include "operators/fuzzy_hash.h"
#include "operators/ge.h"
#include "operators/geo_lookup.h"
#include "operators/gsblookup.h"
#include "operators/gt.h"
#include "operators/inspect_file.h"
#include "operators/ip_match_f.h"
#include "operators/ip_match_from_file.h"
#include "operators/ip_match.h"
#include "operators/le.h"
#include "operators/lt.h"
#include "operators/no_match.h"
#include "operators/operator.h"
#include "operators/pm_f.h"
#include "operators/pm_from_file.h"
#include "operators/pm.h"
#include "operators/rbl.h"
#include "operators/rsub.h"
#include "operators/rx.h"
#include "operators/str_eq.h"
#include "operators/str_match.h"
#include "operators/validate_byte_range.h"
#include "operators/validate_dtd.h"
#include "operators/validate_hash.h"
#include "operators/validate_schema.h"
#include "operators/validate_url_encoding.h"
#include "operators/validate_utf8_encoding.h"
#include "operators/verify_cc.h"
#include "operators/verify_cpf.h"
#include "operators/verify_ssn.h"
#include "operators/within.h"


using namespace modsecurity::actions::transformations;
using namespace modsecurity::operators;
using namespace modsecurity;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>


int main(int argc, char** argv) {
    size_t count;
    uint8_t buf[128]; 
    ssize_t read_bytes;

    std::string lastString;

    while (__AFL_LOOP(1000)) {
        // (re-) initialize the library and read new input
        read_bytes = -1; 
        memset(buf, 0, 128);
        read_bytes = read(STDIN_FILENO, buf, 128);

        std::string currentString = std::string(read_bytes, 128);
        std::string s = currentString;
        std::string z = lastString;

        ModSecurity *ms = new ModSecurity();
        Rules *rules = new Rules();
        Transaction *transaction = new Transaction(ms, rules, NULL);


        /**
        * Transformations, generated by:
        *
        * for i in $(grep "class " -Ri * | grep " :" | grep -v "InstantCache" | awk {'print $2'}); do echo $i *$(echo $i | awk '{print tolower($0)}') = new $i\(\"$i\"\)\; $(echo $i | awk '{print tolower($0)}')-\>evaluate\(s, NULL\)\; delete $(echo $i | awk '{print tolower($0)}')\;; done;
        *
        */
#if 1
Base64DecodeExt *base64decodeext = new Base64DecodeExt("Base64DecodeExt"); base64decodeext->evaluate(s, NULL); delete base64decodeext;
Base64Decode *base64decode = new Base64Decode("Base64Decode"); base64decode->evaluate(s, NULL); delete base64decode;
CmdLine *cmdline = new CmdLine("CmdLine"); cmdline->evaluate(s, NULL); delete cmdline;
CompressWhitespace *compresswhitespace = new CompressWhitespace("CompressWhitespace"); compresswhitespace->evaluate(s, NULL); delete compresswhitespace;
CssDecode *cssdecode = new CssDecode("CssDecode"); cssdecode->evaluate(s, NULL); delete cssdecode;
EscapeSeqDecode *escapeseqdecode = new EscapeSeqDecode("EscapeSeqDecode"); escapeseqdecode->evaluate(s, NULL); delete escapeseqdecode;
HexDecode *hexdecode = new HexDecode("HexDecode"); hexdecode->evaluate(s, NULL); delete hexdecode;
HexEncode *hexencode = new HexEncode("HexEncode"); hexencode->evaluate(s, NULL); delete hexencode;
//HtmlEntityDecode *htmlentitydecode = new HtmlEntityDecode("HtmlEntityDecode"); htmlentitydecode->evaluate(s, NULL); delete htmlentitydecode;
JsDecode *jsdecode = new JsDecode("JsDecode"); jsdecode->evaluate(s, NULL); delete jsdecode;
Length *length = new Length("Length"); length->evaluate(s, NULL); delete length;
LowerCase *lowercase = new LowerCase("LowerCase"); lowercase->evaluate(s, NULL); delete lowercase;
Md5 *md5 = new Md5("Md5"); md5->evaluate(s, NULL); delete md5;
None *none = new None("None"); none->evaluate(s, NULL); delete none;
NormalisePath *normalisepath = new NormalisePath("NormalisePath"); normalisepath->evaluate(s, NULL); delete normalisepath;
NormalisePathWin *normalisepathwin = new NormalisePathWin("NormalisePathWin"); normalisepathwin->evaluate(s, NULL); delete normalisepathwin;
ParityEven7bit *parityeven7bit = new ParityEven7bit("ParityEven7bit"); parityeven7bit->evaluate(s, NULL); delete parityeven7bit;
ParityOdd7bit *parityodd7bit = new ParityOdd7bit("ParityOdd7bit"); parityodd7bit->evaluate(s, NULL); delete parityodd7bit;
ParityZero7bit *parityzero7bit = new ParityZero7bit("ParityZero7bit"); parityzero7bit->evaluate(s, NULL); delete parityzero7bit;
RemoveCommentsChar *removecommentschar = new RemoveCommentsChar("RemoveCommentsChar"); removecommentschar->evaluate(s, NULL); delete removecommentschar;
RemoveComments *removecomments = new RemoveComments("RemoveComments"); removecomments->evaluate(s, NULL); delete removecomments;
RemoveNulls *removenulls = new RemoveNulls("RemoveNulls"); removenulls->evaluate(s, NULL); delete removenulls;
RemoveWhitespace *removewhitespace = new RemoveWhitespace("RemoveWhitespace"); removewhitespace->evaluate(s, NULL); delete removewhitespace;
ReplaceComments *replacecomments = new ReplaceComments("ReplaceComments"); replacecomments->evaluate(s, NULL); delete replacecomments;
ReplaceNulls *replacenulls = new ReplaceNulls("ReplaceNulls"); replacenulls->evaluate(s, NULL); delete replacenulls;
Sha1 *sha1 = new Sha1("Sha1"); sha1->evaluate(s, NULL); delete sha1;
SqlHexDecode *sqlhexdecode = new SqlHexDecode("SqlHexDecode"); sqlhexdecode->evaluate(s, NULL); delete sqlhexdecode;
Transformation *transformation = new Transformation("Transformation"); transformation->evaluate(s, NULL); delete transformation;
Trim *trim = new Trim("Trim"); trim->evaluate(s, NULL); delete trim;
TrimLeft *trimleft = new TrimLeft("TrimLeft"); trimleft->evaluate(s, NULL); delete trimleft;
TrimRight *trimright = new TrimRight("TrimRight"); trimright->evaluate(s, NULL); delete trimright;
UrlDecode *urldecode = new UrlDecode("UrlDecode"); urldecode->evaluate(s, NULL); delete urldecode;
//UrlDecodeUni *urldecodeuni = new UrlDecodeUni("UrlDecodeUni"); urldecodeuni->evaluate(s, NULL); delete urldecodeuni;
UrlEncode *urlencode = new UrlEncode("UrlEncode"); urlencode->evaluate(s, NULL); delete urlencode;
Utf8Unicode *utf8unicode = new Utf8Unicode("Utf8Unicode"); utf8unicode->evaluate(s, NULL); delete utf8unicode;
#endif


        /**
        * Operators, generated by:
        *
        * for i in $(grep "class " -Ri * | grep " :" | grep -v "InstantCache" | awk {'print $2'}); do echo $i *$(echo $i | awk '{print tolower($0)}') = new $i\(\"$i\"\)\; $(echo $i | awk '{print tolower($0)}')-\>evaluate\(s, NULL\)\; delete $(echo $i | awk '{print tolower($0)}')\;; done;
        *
        */
#if 1
BeginsWith *beginswith = new BeginsWith("@BeginsWith", z, false); beginswith->evaluate(transaction, s); delete beginswith;
Contains *contains = new Contains("@Contains", z, false); contains->evaluate(transaction, s); delete contains;
ContainsWord *containsword = new ContainsWord("@ContainsWord", z, false); containsword->evaluate(transaction, s); delete containsword;
DetectSQLi *detectsqli = new DetectSQLi("@DetectSQLi", z, false); detectsqli->evaluate(transaction, s); delete detectsqli;
DetectXSS *detectxss = new DetectXSS("@DetectXSS", z, false); detectxss->evaluate(transaction, s); delete detectxss;
EndsWith *endswith = new EndsWith("@EndsWith", z, false); endswith->evaluate(transaction, s); delete endswith;
Eq *eq = new Eq("@Eq", z, false); eq->evaluate(transaction, s); delete eq;
FuzzyHash *fuzzyhash = new FuzzyHash("@FuzzyHash", z, false); fuzzyhash->evaluate(transaction, s); delete fuzzyhash;
Ge *ge = new Ge("@Ge", z, false); ge->evaluate(transaction, s); delete ge;
GeoLookup *geolookup = new GeoLookup("@GeoLookup", z, false); geolookup->evaluate(transaction, s); delete geolookup;
GsbLookup *gsblookup = new GsbLookup("@GsbLookup", z, false); gsblookup->evaluate(transaction, s); delete gsblookup;
Gt *gt = new Gt("@Gt", z, false); gt->evaluate(transaction, s); delete gt;
InspectFile *inspectfile = new InspectFile("@InspectFile", z, false); inspectfile->evaluate(transaction, s); delete inspectfile;
IpMatchF *ipmatchf = new IpMatchF("@IpMatchF", z, false); ipmatchf->evaluate(transaction, s); delete ipmatchf;
IpMatchFromFile *ipmatchfromfile = new IpMatchFromFile("@IpMatchFromFile", z, false); ipmatchfromfile->evaluate(transaction, s); delete ipmatchfromfile;
IpMatch *ipmatch = new IpMatch("@IpMatch", z, false); ipmatch->evaluate(transaction, s); delete ipmatch;
Le *le = new Le("@Le", z, false); le->evaluate(transaction, s); delete le;
Lt *lt = new Lt("@Lt", z, false); lt->evaluate(transaction, s); delete lt;
NoMatch *nomatch = new NoMatch("@NoMatch", z, false); nomatch->evaluate(transaction, s); delete nomatch;
PmF *pmf = new PmF("@PmF", z, false); pmf->evaluate(transaction, s); delete pmf;
PmFromFile *pmfromfile = new PmFromFile("@PmFromFile", z, false); pmfromfile->evaluate(transaction, s); delete pmfromfile;
Pm *pm = new Pm("@Pm", z, false); pm->evaluate(transaction, s); delete pm;
Rbl *rbl = new Rbl("@Rbl", z, false); rbl->evaluate(transaction, s); delete rbl;
Rsub *rsub = new Rsub("@Rsub", z, false); rsub->evaluate(transaction, s); delete rsub;
Rx *rx = new Rx("@Rx", z, false); rx->evaluate(transaction, s); delete rx;
StrEq *streq = new StrEq("@StrEq", z, false); streq->evaluate(transaction, s); delete streq;
StrMatch *strmatch = new StrMatch("@StrMatch", z, false); strmatch->evaluate(transaction, s); delete strmatch;
ValidateByteRange *validatebyterange = new ValidateByteRange("@ValidateByteRange", z, false); validatebyterange->evaluate(transaction, s); delete validatebyterange;
ValidateDTD *validatedtd = new ValidateDTD("@ValidateDTD", z, false); validatedtd->evaluate(transaction, s); delete validatedtd;
ValidateHash *validatehash = new ValidateHash("@ValidateHash", z, false); validatehash->evaluate(transaction, s); delete validatehash;
ValidateSchema *validateschema = new ValidateSchema("@ValidateSchema", z, false); validateschema->evaluate(transaction, s); delete validateschema;
ValidateUrlEncoding *validateurlencoding = new ValidateUrlEncoding("@ValidateUrlEncoding", z, false); validateurlencoding->evaluate(transaction, s); delete validateurlencoding;
ValidateUtf8Encoding *validateutf8encoding = new ValidateUtf8Encoding("@ValidateUtf8Encoding", z, false); validateutf8encoding->evaluate(transaction, s); delete validateutf8encoding;
VerifyCC *verifycc = new VerifyCC("@VerifyCC", z, false); verifycc->evaluate(transaction, s); delete verifycc;
VerifyCPF *verifycpf = new VerifyCPF("@VerifyCPF", z, false); verifycpf->evaluate(transaction, s); delete verifycpf;
VerifySSN *verifyssn = new VerifySSN("@VerifySSN", z, false); verifyssn->evaluate(transaction, s); delete verifyssn;
Within *within = new Within("@Within", z, false); within->evaluate(transaction, s); delete within;
#endif


        /**
        * ModSec API
        *
        */
#if 0
    transaction->processConnection(s.c_str(), 123, s.c_str(), 123);
    transaction->processURI(s.c_str(), z.c_str(), z.c_str());
    transaction->addRequestHeader(s, z);
    transaction->addRequestHeader(s, s);
    transaction->addRequestHeader(z, z);
    transaction->addRequestHeader(z, s);
    transaction->processRequestHeaders();
    transaction->appendRequestBody((const unsigned char *)s.c_str(), s.length());
    transaction->processRequestBody();
    transaction->addResponseHeader(s, z);
    transaction->addResponseHeader(s, s);
    transaction->addResponseHeader(z, z);
    transaction->addResponseHeader(z, s);
    transaction->processResponseHeaders();
    transaction->appendResponseBody((const unsigned char *)s.c_str(), s.length());
    transaction->processResponseBody();
#endif


        delete transaction;
        delete rules;
        delete ms;

        lastString = currentString;
    }
    return 0;
}
