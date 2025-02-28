/**
 * Google's Cloud Firestore class, Forestore.h version 1.1.8
 * 
 * This library supports Espressif ESP8266 and ESP32
 * 
 * Created December 20, 2021
 * 
 * This work is a part of Firebase ESP Client library
 * Copyright (c) 2021 K. Suwatchai (Mobizt)
 * 
 * The MIT License (MIT)
 * Copyright (c) 2021 K. Suwatchai (Mobizt)
 * 
 * 
 * Permission is hereby granted, free of charge, to any person returning a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "FirebaseFS.h"

#ifdef ENABLE_FIRESTORE

#ifndef _FB_FIRESTORE_H_
#define _FB_FIRESTORE_H_

#include <Arduino.h>
#include "Utils.h"
#include "session/FB_Session.h"
#include "json/FirebaseJson.h"

class FB_Firestore
{
    friend class Firebase_ESP_Client;

public:
    FB_Firestore();
    ~FB_Firestore();

    /** Export the documents in the database to the Firebase Storage data bucket.
     * 
     * @param fbdo The pointer to Firebase Data Object.
     * @param projectId The Firebase project id (only the name without the firebaseio.com).
     * @param databaseId The Firebase Cloud Firestore database id which is (default) or empty "".
     * @param bucketID The Firebase storage bucket ID in the project.
     * @param storagePath The path in the Firebase Storage data bucket to store the exported database.
     * @param collectionIds Which collection ids to export. Unspecified means all collections. Use comma (,) to separate between the collection ids.
     * .
     * @return Boolean value, indicates the success of the operation. 
     * 
     * @note Use FirebaseData.payload() to get the returned payload.
     * 
     * This function requires OAuth2.0 authentication.
     * 
    */
    template <typename T1 = const char *, typename T2 = const char *, typename T3 = const char *, typename T4 = const char *, typename T5 = const char *>
    bool exportDocuments(FirebaseData *fbdo, T1 projectId, T2 databaseId, T3 bucketID, T4 storagePath, T5 collectionIds = "") { return mExportDocuments(fbdo, toString(projectId), toString(databaseId), toString(bucketID), toString(storagePath), toString(collectionIds)); }

    /** Import the exported documents stored in the Firebase Storage data bucket.
     * 
     * @param fbdo The pointer to Firebase Data Object.
     * @param projectId The Firebase project id (only the name without the firebaseio.com).
     * @param databaseId The Firebase Cloud Firestore database id which is (default) or empty "".
     * @param bucketID The Firebase storage bucket ID in the project.
     * @param storagePath The path in the Firebase Storage data bucket that stores the exported database.
     * @param collectionIds Which collection ids to import. Unspecified means all collections included in the import. Use comma (,) to separate between the collection ids.
     * .
     * @return Boolean value, indicates the success of the operation. 
     * 
     * @note Use FirebaseData.payload() to get the returned payload.
     * 
     * This function requires OAuth2.0 authentication.
     * 
    */
    template <typename T1 = const char *, typename T2 = const char *, typename T3 = const char *, typename T4 = const char *, typename T5 = const char *>
    bool importDocuments(FirebaseData *fbdo, T1 projectId, T2 databaseId, T3 bucketID, T4 storagePath, T5 collectionIds = "") { return mImportDocuments(fbdo, toString(projectId), toString(databaseId), toString(bucketID), toString(storagePath), toString(collectionIds)); }

    /** Create a document at the defined document path.
     * 
     * @param fbdo The pointer to Firebase Data Object.
     * @param projectId The Firebase project id (only the name without the firebaseio.com).
     * @param databaseId The Firebase Cloud Firestore database id which is (default) or empty "".
     * @param documentPath The relative path of document to create in the collection.
     * @param content A Firestore document. See https://firebase.google.com/docs/firestore/reference/rest/v1/projects.databases.documents#Document
     * @param mask The fields to return. If not set, returns all fields. Use comma (,) to separate between the field names.
     * .
     * @return Boolean value, indicates the success of the operation. 
     * 
     * @note Use FirebaseData.payload() to get the returned payload.
     * 
     * This function requires Email/password, Custom token or OAuth2.0 authentication.
     * 
    */
    template <typename T1 = const char *, typename T2 = const char *, typename T3 = const char *, typename T4 = const char *, typename T5 = const char *>
    bool createDocument(FirebaseData *fbdo, T1 projectId, T2 databaseId, T3 documentPath, T4 content, T5 mask = "") { return mCreateDocument(fbdo, toString(projectId), toString(databaseId), toString(documentPath), toString(content), toString(mask)); }

    /** Create a document in the defined collection id.
     * 
     * @param fbdo The pointer to Firebase Data Object.
     * @param projectId The Firebase project id (only the name without the firebaseio.com).
     * @param databaseId The Firebase Cloud Firestore database id which is (default) or empty "".
     * @param collectionId The relative path of document collection id to create the document.
     * @param documentId The document id of document to be created.
     * @param content A Firestore document. See https://firebase.google.com/docs/firestore/reference/rest/v1/projects.databases.documents#Document
     * @param mask The fields to return. If not set, returns all fields. Use comma (,) to separate between the field names.
     * .
     * @return Boolean value, indicates the success of the operation. 
     * 
     * @note Use FirebaseData.payload() to get the returned payload.
     * 
     * This function requires Email/password, Custom token or OAuth2.0 authentication.
     * 
    */
    template <typename T1 = const char *, typename T2 = const char *, typename T3 = const char *, typename T4 = const char *, typename T5 = const char *, typename T6 = const char *>
    bool createDocument(FirebaseData *fbdo, T1 projectId, T2 databaseId, T3 collectionId, T4 documentId, T5 content, T6 mask = "") { return mCreateDocument2(fbdo, toString(projectId), toString(databaseId), toString(collectionId), toString(documentId), toString(content), toString(mask)); }

    /** Patch or update a document at the defined path.
     * 
     * @param fbdo The pointer to Firebase Data Object.
     * @param projectId The Firebase project id (only the name without the firebaseio.com).
     * @param databaseId The Firebase Cloud Firestore database id which is (default) or empty "".
     * @param documentPath The relative path of document to patch with the input document.
     * @param content A Firestore document. See https://firebase.google.com/docs/firestore/reference/rest/v1/projects.databases.documents#Document
     * @param updateMask The fields to update. If the document exists on the server and has fields not referenced in the mask, they are left unchanged. 
     * Fields referenced in the mask, but not present in the input document (content), are deleted from the document on the server. 
     * Use comma (,) to separate between the field names.
     * @param mask The fields to return. If not set, returns all fields. If the document has a field that is not present in this mask, that field 
     * will not be returned in the response. Use comma (,) to separate between the field names.
     * @param exists When set to true, the target document must exist. When set to false, the target document must not exist.
     * @param updateTime When set, the target document must exist and have been last updated at that time. 
     * A timestamp in RFC3339 UTC "Zulu" format, with nanosecond resolution and up to nine fractional digits. 
     * Examples: "2014-10-02T15:01:23Z" and "2014-10-02T15:01:23.045123456Z".
     * 
     * @return Boolean value, indicates the success of the operation. 
     * 
     * @note Use FirebaseData.payload() to get the returned payload.
     * 
     * This function requires Email/password, Custom token or OAuth2.0 authentication.
     * 
    */
    template <typename T1 = const char *, typename T2 = const char *, typename T3 = const char *, typename T4 = const char *, typename T5 = const char *, typename T6 = const char *, typename T7 = const char *, typename T8 = const char *>
    bool patchDocument(FirebaseData *fbdo, T1 projectId, T2 databaseId, T3 documentPath, T4 content, T5 updateMask, T6 mask = "", T7 exists = "", T8 updateTime = "") { return mPatchDocument(fbdo, toString(projectId), toString(databaseId), toString(documentPath), toString(content), toString(updateMask), toString(mask), toString(exists), toString(updateTime)); }

    /** Commits a transaction, while optionally updating documents.
     * 
     * @param fbdo The pointer to Firebase Data Object.
     * @param projectId The Firebase project id (only the name without the firebaseio.com).
     * @param databaseId The Firebase Cloud Firestore database id which is (default) or empty "".
     * @param writes The dyamic array of write object fb_esp_firestore_document_write_t.
     * 
     * For the write object, see https://firebase.google.com/docs/firestore/reference/rest/v1/Write
     * 
     * @param transaction A base64-encoded string. If set, applies all writes in this transaction, and commits it.
     * 
     * @return Boolean value, indicates the success of the operation. 
     * 
     * @note Use FirebaseData.payload() to get the returned payload.
     * 
     * This function requires Email/password, Custom token or OAuth2.0 authentication.
     * 
    */
    template <typename T1 = const char *, typename T2 = const char *, typename T3 = const char *>
    bool commitDocument(FirebaseData *fbdo, T1 projectId, T2 databaseId, std::vector<struct fb_esp_firestore_document_write_t> writes, T3 transaction = "") { return mCommitDocument(fbdo, toString(projectId), toString(databaseId), writes, toString(transaction), false); }

    template <typename T1 = const char *, typename T2 = const char *, typename T3 = const char *>
    bool commitDocumentAsync(FirebaseData *fbdo, T1 projectId, T2 databaseId, std::vector<struct fb_esp_firestore_document_write_t> writes, T3 transaction = "") { return mCommitDocument(fbdo, toString(projectId), toString(databaseId), writes, toString(transaction), true); }

    /** Get a document at the defined path.
     * 
     * @param fbdo The pointer to Firebase Data Object.
     * @param projectId The Firebase project id (only the name without the firebaseio.com).
     * @param databaseId The Firebase Cloud Firestore database id which is (default) or empty "".
     * @param documentPath The relative path of document to get.
     * @param mask The fields to return. If not set, returns all fields. If the document has a field that is not present in this mask,
     * that field will not be returned in the response. Use comma (,) to separate between the field names.
     * @param transaction Reads the document in a transaction. A base64-encoded string.
     * @param readTime Reads the version of the document at the given time. This may not be older than 270 seconds.
     * A timestamp in RFC3339 UTC "Zulu" format, with nanosecond resolution and up to nine fractional digits. 
     * Examples: "2014-10-02T15:01:23Z" and "2014-10-02T15:01:23.045123456Z".
     * 
     * @return Boolean value, indicates the success of the operation. 
     * 
     * @note Use FirebaseData.payload() to get the returned payload.
     * 
     * This function requires Email/password, Custom token or OAuth2.0 authentication.
     * 
    */
    template <typename T1 = const char *, typename T2 = const char *, typename T3 = const char *, typename T4 = const char *, typename T5 = const char *, typename T6 = const char *>
    bool getDocument(FirebaseData *fbdo, T1 projectId, T2 databaseId, T3 documentPath, T4 mask = "", T5 transaction = "", T6 readTime = "") { return mGetDocument(fbdo, toString(projectId), toString(databaseId), toString(documentPath), toString(mask), toString(transaction), toString(readTime)); }

    /** Starts a new transaction.
     * 
     * @param fbdo The pointer to Firebase Data Object.
     * @param projectId The Firebase project id (only the name without the firebaseio.com).
     * @param databaseId The Firebase Cloud Firestore database id which is (default) or empty "".
     * @param transactionOptions Optional. The TransactionOptions type data that represents the options for creating a new transaction.
     * 
     * @return Boolean value, indicates the success of the operation. 
     * 
     * @note Use FirebaseData.payload() to get the returned payload.
     * 
     * This function requires OAuth2.0 authentication.
     * 
     * The TransactionOptions struct contains two properties i.e.
     * readOnly and readWrite.
     * 
     * Use readOnly for options for a transaction that can only be used to read documents.
     * Use readWrite for options for a transaction that can be used to read and write documents.
     * 
     * The readOnly property contains one property, readTime.
     * The readTime is for reading the documents at the given time. This may not be older than 60 seconds.
     * A timestamp in RFC3339 UTC "Zulu" format, with nanosecond resolution and up to nine fractional digits. 
     * Examples: "2014-10-02T15:01:23Z" and "2014-10-02T15:01:23.045123456Z". 
     * 
     * The readWrite property contains one property, retryTransaction.
     * The retryTransaction is a base64-encoded string represents a transaction that can be used to read and write documents.
     * 
     * See https://cloud.google.com/firestore/docs/reference/rest/v1/TransactionOptions for transaction options.
    */
    template <typename T1 = const char *, typename T2 = const char *>
    bool beginTransaction(FirebaseData *fbdo, T1 projectId, T2 databaseId, TransactionOptions *transactionOptions = nullptr) { return mBeginTransaction(fbdo, toString(projectId), toString(databaseId), transactionOptions); }

    /** Rolls back a transaction.
     * 
     * @param fbdo The pointer to Firebase Data Object.
     * @param projectId The Firebase project id (only the name without the firebaseio.com).
     * @param databaseId The Firebase Cloud Firestore database id which is (default) or empty "".
     * @param transaction Required. A base64-encoded string of the transaction to roll back.
     * 
     * @return Boolean value, indicates the success of the operation. 
     * 
     * @note Use FirebaseData.payload() to get the returned payload.
     * 
     * This function requires OAuth2.0 authentication.
    */
    template <typename T1 = const char *, typename T2 = const char *, typename T3 = const char *>
    bool rollback(FirebaseData *fbdo, T1 projectId, T2 databaseId, T3 transaction) { return mRollback(fbdo, toString(projectId), toString(databaseId), toString(transaction)); }

    /** Runs a query.
     * 
     * @param fbdo The pointer to Firebase Data Object.
     * @param projectId The Firebase project id (only the name without the firebaseio.com).
     * @param databaseId The Firebase Cloud Firestore database id which is (default) or empty "".
     * @param documentPath The relative path of document to get.
     * @param structuredQuery The pointer to FirebaseJson object that contains the Firestore query. For the description of structuredQuery, see https://cloud.google.com/firestore/docs/reference/rest/v1/StructuredQuery
     * @param consistencyMode Optional. The consistency mode for this transaction e.g. fb_esp_firestore_consistency_mode_transaction,fb_esp_firestore_consistency_mode_newTransaction
     * and fb_esp_firestore_consistency_mode_readTime
     * @param consistency Optional. The value based on consistency mode e.g. transaction string, TransactionOptions (JSON) and date time string.
     * 
     * For more description, see https://cloud.google.com/firestore/docs/reference/rest/v1/projects.databases.documents/runQuery#body.request_body.FIELDS
     * 
     * @return Boolean value, indicates the success of the operation. 
     * 
     * @note Use FirebaseData.payload() to get the returned payload.
     * 
     * 
    */
    template <typename T1 = const char *, typename T2 = const char *, typename T3 = const char *, typename T4 = const char *>
    bool runQuery(FirebaseData *fbdo, T1 projectId, T2 databaseId, T3 documentPath, FirebaseJson *structuredQuery, fb_esp_firestore_consistency_mode consistencyMode = fb_esp_firestore_consistency_mode_undefined, T4 consistency = "") { return mRunQuery(fbdo, toString(projectId), toString(databaseId), toString(documentPath), structuredQuery, consistencyMode, toString(consistency)); }

    /** Delete a document at the defined path.
     * 
     * @param fbdo The pointer to Firebase Data Object.
     * @param projectId The Firebase project id (only the name without the firebaseio.com).
     * @param databaseId The Firebase Cloud Firestore database id which is (default) or empty "".
     * @param documentPath The relative path of document to delete.
     * @param exists When set to true, the target document must exist. When set to false, the target document must not exist.
     * @param updateTime When set, the target document must exist and have been last updated at that time.
     * A timestamp in RFC3339 UTC "Zulu" format, with nanosecond resolution and up to nine fractional digits.
     * Examples: "2014-10-02T15:01:23Z" and "2014-10-02T15:01:23.045123456Z".
     * 
     * @return Boolean value, indicates the success of the operation. 
     * 
     * 
     * This function requires Email/password, Custom token or OAuth2.0 authentication.
     * 
    */
    template <typename T1 = const char *, typename T2 = const char *, typename T3 = const char *, typename T4 = const char *, typename T5 = const char *>
    bool deleteDocument(FirebaseData *fbdo, T1 projectId, T2 databaseId, T3 documentPath, T4 exists = "", T5 updateTime = "") { return mDeleteDocument(fbdo, toString(projectId), toString(databaseId), toString(documentPath), toString(exists), toString(updateTime)); }

    /** List the documents in the defined documents collection.
     * 
     * @param fbdo The pointer to Firebase Data Object.
     * @param projectId The Firebase project id (only the name without the firebaseio.com).
     * @param databaseId The Firebase Cloud Firestore database id which is (default) or empty "".
     * @param collectionId The relative path of document colection.
     * @param pageSize The maximum number of documents to return.
     * @param pageToken The nextPageToken value returned from a previous List request, if any.
     * @param orderBy The order to sort results by. For example: priority desc, name.
     * @param mask The fields to return. If not set, returns all fields.
     * If a document has a field that is not present in this mask, that field will not be returned in the response.
     * @param showMissing If the list should show missing documents. 
     * A missing document is a document that does not exist but has sub-documents. 
     * 
     * @return Boolean value, indicates the success of the operation. 
     * 
     * @note Use FirebaseData.payload() to get the returned payload.
     * 
     * This function requires Email/password, Custom token or OAuth2.0 authentication (when showMissing is true).
     * 
    */
    template <typename T1 = const char *, typename T2 = const char *, typename T3 = const char *, typename T4 = size_t, typename T5 = const char *, typename T6 = const char *, typename T7 = const char *>
    bool listDocuments(FirebaseData *fbdo, T1 projectId, T2 databaseId, T3 collectionId, T4 pageSize, T5 pageToken, T6 orderBy, T7 mask, bool showMissing) { return mListDocuments(fbdo, toString(projectId), toString(databaseId), toString(collectionId), NUM2S(pageSize).get(), toString(pageToken), toString(orderBy), toString(mask), showMissing); }

    /** List the document collection ids in the defined document path.
     * 
     * @param fbdo The pointer to Firebase Data Object.
     * @param projectId The Firebase project id (only the name without the firebaseio.com).
     * @param databaseId The Firebase Cloud Firestore database id which is (default) or empty "".
     * @param documentPath The relative path of document to get its collections' id.
     * @param pageSize The maximum number of results to return.
     * @param pageToken The nextPageToken value returned from a previous List request, if any.
     * 
     * @return Boolean value, indicates the success of the operation. 
     * 
     * @note Use FirebaseData.payload() to get the returned payload.
     * 
    */
    template <typename T1 = const char *, typename T2 = const char *, typename T3 = const char *, typename T4 = size_t, typename T5 = const char *>
    bool listCollectionIds(FirebaseData *fbdo, T1 projectId, T2 databaseId, T3 documentPath, T4 pageSize, T5 pageToken) { return mListCollectionIds(fbdo, toString(projectId), toString(databaseId), toString(documentPath), NUM2S(pageSize).get(), toString(pageToken)); }

private:
    UtilsClass *ut = nullptr;
    void begin(UtilsClass *u);
    void rescon(FirebaseData *fbdo, const char *host);
    bool connect(FirebaseData *fbdo);
    bool sendRequest(FirebaseData *fbdo, struct fb_esp_firestore_req_t *req);
    bool firestore_sendRequest(FirebaseData *fbdo, struct fb_esp_firestore_req_t *req);
    bool handleResponse(FirebaseData *fbdo);
    bool setFieldTransform(FirebaseJson *json, struct fb_esp_firestore_document_write_field_transforms_t *field_transforms);
    bool mCommitDocument(FirebaseData *fbdo, const char *projectId, const char *databaseId, std::vector<struct fb_esp_firestore_document_write_t> writes, const char *transaction = "", bool async = false);
    bool mExportDocuments(FirebaseData *fbdo, const char *projectId, const char *databaseId, const char *bucketID, const char *storagePath, const char *collectionIds = "");
    bool mImportDocuments(FirebaseData *fbdo, const char *projectId, const char *databaseId, const char *bucketID, const char *storagePath, const char *collectionIds = "");
    bool mCreateDocument(FirebaseData *fbdo, const char *projectId, const char *databaseId, const char *documentPath, const char *content, const char *mask = "");
    bool mCreateDocument2(FirebaseData *fbdo, const char *projectId, const char *databaseId, const char *collectionId, const char *documentId, const char *content, const char *mask = "");
    bool mPatchDocument(FirebaseData *fbdo, const char *projectId, const char *databaseId, const char *documentPath, const char *content, const char *updateMask, const char *mask = "", const char *exists = "", const char *updateTime = "");
    bool mGetDocument(FirebaseData *fbdo, const char *projectId, const char *databaseId, const char *documentPath, const char *mask = "", const char *transaction = "", const char *readTime = "");
    bool mBeginTransaction(FirebaseData *fbdo, const char *projectId, const char *databaseId, TransactionOptions *transactionOptions = nullptr);
    bool mRollback(FirebaseData *fbdo, const char *projectId, const char *databaseId, const char *transaction);
    bool mRunQuery(FirebaseData *fbdo, const char *projectId, const char *databaseId, const char *documentPath, FirebaseJson *structuredQuery, fb_esp_firestore_consistency_mode consistencyMode = fb_esp_firestore_consistency_mode_undefined, const char *consistency = "");
    bool mDeleteDocument(FirebaseData *fbdo, const char *projectId, const char *databaseId, const char *documentPath, const char *exists = "", const char *updateTime = "");
    bool mListDocuments(FirebaseData *fbdo, const char *projectId, const char *databaseId, const char *collectionId, const char* pageSize, const char *pageToken, const char *orderBy, const char *mask, bool showMissing);
    bool mListCollectionIds(FirebaseData *fbdo, const char *projectId, const char *databaseId, const char *documentPath, const char* pageSize, const char *pageToken);

protected:
    template <typename T>
    auto toString(const T &val) -> typename FB_JS::enable_if<FB_JS::is_std_string<T>::value || FB_JS::is_arduino_string<T>::value || FB_JS::is_mb_string<T>::value || FB_JS::is_same<T, StringSumHelper>::value, const char *>::type { return val.c_str(); }

    template <typename T>
    auto toString(T val) -> typename FB_JS::enable_if<FB_JS::is_const_chars<T>::value, const char *>::type { return val; }

    template <typename T>
    auto toString(T val) -> typename FB_JS::enable_if<FB_JS::fs_t<T>::value, const char *>::type { return (const char *)val; }

    template <typename T>
    auto toString(T val) -> typename FB_JS::enable_if<FB_JS::is_same<T, std::nullptr_t>::value, const char *>::type { return ""; }
};

#endif

#endif //ENABLE