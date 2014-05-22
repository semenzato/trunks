// Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "result_constants.h"

#include <string>

#include "tss/tcs_error.h"
#include "tss/tss_error.h"
#include "tss/tpm_error.h"

namespace trunks {

// Defined on p.95 of TSS specification.
const ResultTablePair kGenericCodeTable[] = {
  { TSS_SUCCESS, "Success." },
  { TSS_E_FAIL, "General failure." },
  { TSS_E_BAD_PARAMETER, "One or more parameters are bad." },
  { TSS_E_INTERNAL_ERROR, "An internal software error has been detected." },
  { TSS_E_NOTIMPL, "Not implemented." },
  { TSS_E_PS_KEY_NOTFOUND, "The key cannot be found in the persistent storage"
                           " database." },
  { TSS_E_KEY_ALREADY_REGISTERED, "Key could not be registered because UUID"
                                  " has already registered." },
  { TSS_E_KEY_NO_MIGRATION_POLICY, "No migration policy available." },
  { TSS_E_CANCELED, "The action was canceled." },
  { TSS_E_TIMEOUT, "The operation has timed out." },
  { TSS_E_OUTOFMEMORY, "Ran out of memory." },
  { TSS_E_TPM_UNEXPECTED, "TPM returns with success but the TSP/TCS has"
                          " noticed that something is amiss." },
  { TSS_E_COMM_FAILURE, "A communications error with the TPM has been"
                        " detected." },
  { TSS_E_TPM_UNSUPPORTED_FEATURE, "The TPM does not support the requested"
                                   " feature." },
  { 0, NULL }
};

// Defined on p.167 of TSS specification.
// There are two errors missing from this table and the header files:
// TSS_TPM_NOT_RESETABLE, TSS_E_WRONG_LOCALITY
const ResultTablePair kTspCodeTable[] = {
  { TSS_SUCCESS, "Success." },
  { TSS_E_INVALID_OBJECT_TYPE, "Object type not valid for this operation." },
  { TSS_E_INVALID_OBJECT_INIT_FLAG, "Invalid object initialization flag." },
  { TSS_E_INVALID_HANDLE, "Invalid object handle." },
  { TSS_E_NO_CONNECTION, "TCS connection has not been established, but is"
                         " required." },
  { TSS_E_CONNECTION_FAILED, "Establishing a connection to Core Service"
                             " failed."},
  { TSS_E_CONNECTION_BROKEN, "Communication with Core Service has been"
                             " established but has since failed." },
  { TSS_E_HASH_INVALID_ALG, "Invalid hash algorithm." },
  { TSS_E_HASH_INVALID_LENGTH, "Hash length is inconsistent with hash"
                               " algorithm." },
  { TSS_E_HASH_NO_DATA, "Hash object has no internal hash value." },
  { TSS_E_SILENT_CONTEXT, "Context is silent, but requires user input." },
  { TSS_E_INVALID_ATTRIB_FLAG, "Flag value for attribfunctions invalid." },
  { TSS_E_INVALID_ATTRIB_SUBFLAG, "Subflag value for attribfunctions"
                                  " invalid." },
  { TSS_E_INVALID_ATTRIB_DATA, "Data for attrib-functions invalid." },
  { TSS_E_NO_PCRS_SET, "No PCR register is selected or set." },
  { TSS_E_KEY_NOT_LOADED, "The addressed key is currently not loaded." },
  { TSS_E_KEY_NOT_SET, "No key information is currently available." },
  { TSS_E_VALIDATION_FAILED, "Internal validation of data failed." },
  { TSS_E_TSP_AUTHREQUIRED, "Authorization is required." },
  { TSS_E_TSP_AUTH2REQUIRED, "Multiple authorization is required." },
  { TSS_E_TSP_AUTHFAIL, "Authorization failed." },
  { TSS_E_TSP_AUTH2FAIL, "Multiple authorization failed." },
  { TSS_E_KEY_NO_MIGRATION_POLICY, "There's no migration policy object set for"
                                   " the addressed key." },
  { TSS_E_POLICY_NO_SECRET, "No secret information is currently available for"
                            " the addressed policy object, but secret"
                            " information is required." },
  { TSS_E_INVALID_OBJ_ACCESS, "The operation failed due to an invalid object"
                              " status." },
  { TSS_E_INVALID_ENCSCHEME, "Invalid encryption scheme." },
  { TSS_E_INVALID_SIGSCHEME, "Invalid signature scheme." },
  { TSS_E_ENC_INVALID_LENGTH, "Invalid length of data to be encrypted." },
  { TSS_E_ENC_NO_DATA, "No data to encrypt." },
  { TSS_E_ENC_INVALID_TYPE, "Invalid encryption type." },
  { TSS_E_INVALID_KEYUSAGE, "Invalid key usage." },
  { TSS_E_VERIFICATION_FAILED, "Verification of signature failed." },
  { TSS_E_HASH_NO_IDENTIFIER, "The hash algorithm identifier is not set." },
  { TSS_E_BAD_PARAMETER, "One of the parameters was not as expected." },
  { TSS_E_INTERNAL_ERROR, "TPM internal error." },
  { TSS_E_INVALID_RESOURCE, "Pointer to memory wrong." },
  { TSS_E_PS_KEY_NOTFOUND, "Key not in persistent storage." },
  { TSS_E_NOTIMPL, "Function not implemented." },
  { TSS_E_KEY_NO_MIGRATION_POLICY, "Need a migration authorization set." },
  { TSS_E_NV_AREA_NOT_EXIST, "The non-volatile area referenced doesn't"
                             " exist." },
  { TSS_E_DAA_ISSUER_KEY_ERROR, "DAA Issuer’s authentication key chain could"
                                " not be verified or is not correct." },
  { TSS_E_DAA_CREDENTIAL_PROOF_ERROR, "Verification of the credential"
                                      " TSS_DAA_CRED_ISSUER issued by the DAA"
                                      " Issuer has failed." },
  { TSS_E_DAA_AUTHENTICATION_ERROR, "The TPM could not be authenticated by the"
                                    " DAA Issuer." },
  { TSS_E_DAA_PSEUDONYM_ERROR, "While verifying the pseudonym of the TPM, the"
                               " private key of the TPM was found on the rogue"
                               " list." },
  { TSS_E_DAA_AR_DECRYPTION_ERROR, "Decryption of the encrypted pseudonym has"
                                   " failed, due to either a wrong secret key"
                                   " or a wrong decryption condition." },
  { TSS_E_DAA_CREDENTIAL_REQUEST_PROOF_ERROR, "Verification of the credential"
                                              " TSS_DAA_CREDL_ISSUER issued by"
                                              " the DAA issuer failed." },
  { TSS_E_NV_AREA_EXIST, "Attempt to define an area that already exists." },
  { TSS_E_NO_ACTIVE_COUNTER, "The TPM does not have an active counter yet." },
  { 0, NULL }
};

// Defined on p.506 of the TSS specification.
const ResultTablePair kTcsCodeTable[] = {
  { TCS_SUCCESS, "Success." },
  { TCS_E_FAIL, "General failure." },
  { TCS_E_KEY_MISMATCH, "Key addressed by the application key handle does not"
                        " match the key addressed by the given UUID." },
  { TCS_E_KM_LOADFAILED, "Key addressed by the Key's UUID cannot be loaded"
                         " because one of the required parent keys needs"
                         " authorization." },
  { TCS_E_KEY_CONTEXT_RELOAD, "The Key Cache Manager could not reload the key"
                              " into the TPM." },
  { TCS_E_INVALID_CONTEXTHANDLE, "The context handle supplied is invalid." },
  { TCS_E_INVALID_KEYHANDLE, "The key handle supplied is invalid." },
  { TCS_E_INVALID_AUTHHANDLE, "The authorization session handle supplied is"
                              " invalid." },
  { TCS_E_INVALID_AUTHSESSION, "The authorization session has been closed by"
                               " the TPM." },
  { TCS_E_INVALID_KEY, "The key has been unloaded by the TPM." },
  { TCS_E_KEY_ALREADY_REGISTERED, "Key is already registered." },
  { TCS_E_KEY_NOT_REGISTERED, "Key isn't registered." },
  { TCS_E_KEY_CONTEXT_RELOAD, "Need to reload the key context." },
  { TCS_E_BAD_INDEX, "Bad memory index." },
  { TCS_E_BAD_PARAMETER, "Bad parameter." },
  { TCS_E_OUTOFMEMORY, "TPM out of memory." },
  { TCS_E_SIZE, "PCR size is wrong." },
  { TCS_E_NOTIMPL, "Command not implemented." },
  { TCS_E_INTERNAL_ERROR, "TPM internal error." },
  { TCS_E_VERIFICATION_FAILED, "Field upgrade verification error." },
  { TCS_E_MAXNVWRITES, "TPM NVRAM has its max writes." },
  { TCS_E_BAD_DELEGATE, "Delegate authorization failed." },
  { TCS_E_INVALID_COUNTER_HANDLE, "Counter handle not valid." },
  { 0, NULL }
};

// The TDDL is not implemented, thus we should need any error codes for it.
const ResultTablePair kTddlCodeTable[] = {
  { 0, NULL }
};

// Defined on p.119 of TPM 1.2 Specification, also from tss/tpm_error.h .
const ResultTablePair kTpm12CodeTable[] = {
  { TPM_E_AUTHFAIL, "Authentication failed." },
  { TPM_E_BADINDEX, "The index to a PCR, DIR or other register is"
                    " incorrect." },
  { TPM_E_BAD_PARAMETER, "One or more parameters are bad." },
  { TPM_E_AUDITFAILURE, "An operation completed successfully but the auditing"
                        " of that operation failed." },
  { TPM_E_CLEAR_DISABLED, "The clear disable flag is set and all clear"
                          " operations now require physical access." },
  { TPM_E_DEACTIVATED, "The TPM is deactivated." },
  { TPM_E_DISABLED, "The TPM is disabled." },
  { TPM_E_DISABLED_CMD, "The target command has been disabled." },
  { TPM_E_FAIL, "The operation failed." },
  { TPM_E_BAD_ORDINAL, "The ordinal was unknown or inconsistent." },
  { TPM_E_INSTALL_DISABLED, "The ability to install an owner is disabled." },
  { TPM_E_INVALID_KEYHANDLE, "The key handle can not be interpreted." },
  { TPM_E_KEYNOTFOUND, "The key handle points to an invalid key." },
  { TPM_E_INAPPROPRIATE_ENC, "Unacceptable encryption scheme." },
  { TPM_E_MIGRATEFAIL, "Migration authorization failed." },
  { TPM_E_INVALID_PCR_INFO, "PCR information could not be interpreted." },
  { TPM_E_NOSPACE, "No room to load key." },
  { TPM_E_NOSRK, "There is no SRK set." },
  { TPM_E_NOTSEALED_BLOB, "An encrypted blob is invalid or was not created"
                          " by this TPM." },
  { TPM_E_OWNER_SET, "There is already an owner set for this TPM." },
  { TPM_E_RESOURCES, "The TPM has insufficient internal rsources to perform"
                     " the requested action." },
  { TPM_E_SHORTRANDOM, "The random string was too short." },
  { TPM_E_SIZE, "The TPM does not have the space to perform the operation." },
  { TPM_E_WRONGPCRVAL, "The named PCR value does not match the current PCR"
                       " value." },
  { TPM_E_BAD_PARAM_SIZE, "The parameter size argument to the command has the"
                          " incorrect value." },
  { TPM_E_SHA_THREAD, "There is no existing SHA-1 thread." },
  { TPM_E_SHA_ERROR, "The calculation is unable to proceed because the"
                     " existing SHA-1 thread has already encountered an"
                     " error." },
  { TPM_E_FAILEDSELFTEST, "Self-test has failed and the TPM has shut down." },
  { TPM_E_AUTH2FAIL, "The authorization for the second key in a 2-key function"
                     " failed authorization." },
  { TPM_E_BADTAG, "The tag value sent for a command is invalid." },
  { TPM_E_IOERROR, "An IO error occurred transmitting information to the"
                   " TPM." },
  { TPM_E_ENCRYPT_ERROR, "The encryption process had a problem." },
  { TPM_E_DECRYPT_ERROR, "The decryption process did not complete." },
  { TPM_E_INVALID_AUTHHANDLE, "An invalid handle was used." },
  { TPM_E_NO_ENDORSEMENT, "The TPM does not have an EK installed." },
  { TPM_E_INVALID_KEYUSAGE, "The usage of a key is not allowed." },
  { TPM_E_WRONG_ENTITYTYPE, "The submitted entity type is not allowed." },
  { TPM_E_INVALID_POSTINIT, "The command was received in the wrong sequence"
                            " relative to TPM_Init and a subsequent"
                            " TPM_Startup." },
  { TPM_E_INAPPROPRIATE_SIG, "Signed data cannot include additional DER"
                             " information." },
  { TPM_E_BAD_KEY_PROPERTY, "The key properties in TPM_KEY_PARMs are not"
                            " supported by this TPM." },
  { TPM_E_BAD_MIGRATION, "The migration properties of this key are"
                         " incorrect." },
  { TPM_E_BAD_SCHEME, "The signature or encryption scheme for this key is"
                      " incorrect or not permitted in this situation." },
  { TPM_E_BAD_DATASIZE, "The size of the data (or blob) parameter is bad"
                        " or inconsistent with the referenced key." },
  { TPM_E_BAD_MODE, "A mode parameter is bad, such as capArea or subCapArea"
                    " for TPM_GetCapability, physicalPresence parameter for"
                    " TPM_PhysicalPresence, or migrationType for"
                    " TPM_CreateMigrationBlob." },
  { TPM_E_BAD_PRESENCE, "Either the physicalPresence or physicalPresenceLock"
                        " bits have the wrong value." },
  { TPM_E_BAD_VERSION, "The TPM cannot perform this version of the"
                       " capability." },
  { TPM_E_NO_WRAP_TRANSPORT, "The TPM does not allow for wrapped transport"
                             " sessions." },
  { TPM_E_AUDITFAIL_UNSUCCESSFUL, "TPM audit construction failed and the"
                                  " underlying command was returning a failure"
                                  " code also." },
  { TPM_E_AUDITFAIL_SUCCESSFUL, "TPM audit construction failed and the"
                                " underlying command was returning success." },
  { TPM_E_NOTRESETABLE, "Attempt to reset a PCR register that does not have"
                        " the resettable attribute." },
  { TPM_E_NOTLOCAL, "Attempt to reset a PCR register that requires locality"
                    " and locality modifier not part of command transport." },
  { TPM_E_BAD_TYPE, "Make identity blob not properly typed." },
  { TPM_E_INVALID_RESOURCE, "When saving context identified resource type"
                            " does not match actual resource." },
  { TPM_E_NOTFIPS, "The TPM is attempting to execute a command only available"
                   " when in FIPS mode." },
  { TPM_E_INVALID_FAMILY, "The command is attempting to use an invalid family"
                          " ID." },
  { TPM_E_NO_NV_PERMISSION, "The permission to manipulate the NV storage is"
                            " not available." },
  { TPM_E_REQUIRES_SIGN, "The operation requires a signed command." },
  { TPM_E_KEY_NOTSUPPORTED, "Wrong operation to load an NV key." },
  { TPM_E_AUTH_CONFLICT, "NV_LoadKey blob requires both owner and blob"
                         " authorization." },
  { TPM_E_AREA_LOCKED, "The NV area is locked and not writable." },
  { TPM_E_BAD_LOCALITY, "The locality is incorrect for the attempted"
                        " operation." },
  { TPM_E_READ_ONLY, "The NV area is read only and can't be written to." },
  { TPM_E_PER_NOWRITE, "There is no protection on the write to the NV area." },
  { TPM_E_FAMILYCOUNT, "The family count value does not match." },
  { TPM_E_WRITE_LOCKED, "The NV area has already been written to." },
  { TPM_E_BAD_ATTRIBUTES, "The NV area attributes conflict." },
  { TPM_E_INVALID_STRUCTURE, "The structure tag and version are invalid or"
                             " inconsistent." },
  { TPM_E_KEY_OWNER_CONTROL, "The key is under control of the TPM Owner and"
                             " can only be evicted by the TPM Owner." },
  { TPM_E_BAD_COUNTER, "The counter handle is incorrect." },
  { TPM_E_NOT_FULLWRITE, "The write is not a complete write of the area." },
  { TPM_E_CONTEXT_GAP, "The gap between saved context counts is too large." },
  { TPM_E_MAXNVWRITES, "The maximum number of NV writes without an owner has"
                       " been exceeded." },
  { TPM_E_NOOPERATOR, "No operator AuthData value is set." },
  { TPM_E_RESOURCEMISSING, "The resource pointed to by context is not"
                           " loaded." },
  { TPM_E_DELEGATE_LOCK, "The delegate administration is locked." },
  { TPM_E_DELEGATE_FAMILY, "Attempt to manage a family other then the"
                           " delegated family." },
  { TPM_E_DELEGATE_ADMIN, "Delegation table management not enabled." },
  { TPM_E_TRANSPORT_NOTEXCLUSIVE, "There was a command executed outside of an"
                                  " exclusive transport session." },
  { TPM_E_OWNER_CONTROL, "Attempt to context save a owner evict controlled"
                         " key." },
  { TPM_E_DAA_RESOURCES, "The DAA command has no resources available to"
                         " execute the command." },
  { TPM_E_DAA_INPUT_DATA0, "The consistency check on DAA parameter inputData0"
                            " has failed." },
  { TPM_E_DAA_INPUT_DATA1, "The consistency check on DAA parameter inputData1"
                            " has failed." },
  { TPM_E_DAA_ISSUER_SETTINGS, "The consistency check on DAA_issuerSettings"
                               " has failed." },
  { TPM_E_DAA_TPM_SETTINGS, "The consistency check on DAA_tpmSpecific has"
                            " failed." },
  { TPM_E_DAA_STAGE, "The atomic process indicated by the submitted DAA"
                     " command is not the expected process." },
  { TPM_E_DAA_ISSUER_VALIDITY, "The issuer's validity check has detected"
                               " an inconsistency." },
  { TPM_E_DAA_WRONG_W, "The consistency check on w has failed." },
  { TPM_E_BAD_HANDLE, "The handle is incorrect." },
  { TPM_E_BAD_DELEGATE, "Delegation is not correct." },
  { TPM_E_BADCONTEXT, "The context blob is invalid." },
  { TPM_E_TOOMANYCONTEXTS, "Too many contexts held by the TPM." },
  { TPM_E_MA_TICKET_SIGNATURE, "Migration authority signature validation"
                               " failure." },
  { TPM_E_MA_DESTINATION, "Migration destination not authenticated." },
  { TPM_E_MA_SOURCE, "Migration source incorrect." },
  { TPM_E_MA_AUTHORITY, "Incorrect migration authority." },
  { TPM_E_PERMANENTEK, "Attempt to revoke the EK and the EK is not"
                       " revocable." },
  { TPM_E_BAD_SIGNATURE, "Bad signature of CMK ticket." },
  { TPM_E_NOCONTEXTSPACE, "There is no room in the context list for additional"
                          " contexts." },
  { TPM_E_RETRY, "The TPM is too busy to respond to a command immediately,"
                 " but the command could be resubmitted at a later time." },
  { TPM_E_NEEDS_SELFTEST, "TPM_ContinueSelfTest has not be run." },
  { TPM_E_DOING_SELFTEST, "The TPM is currently executing the actions of"
                          " TPM_ContinueSelfTest because the ordinal required"
                          " resources that have not been tested." },
  { TPM_E_DEFEND_LOCK_RUNNING, "The TPM is defending against dictionary"
                               " attacks and is in some time-out period." },
  { 0, NULL }
};

// Return code lookup table.
const ResultTable kResultTable[] = {
  { "TPM", kTpm12CodeTable },
  { "TDDL", kTddlCodeTable },
  { "TCS", kTcsCodeTable },
  { "TSP", kTspCodeTable },
};

}  // namespace trunks
