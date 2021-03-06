#pragma once

#include "cad/const.h"
#include "cad/document/storagemanager.h"

namespace lc {

    class Document;
    class StorageManager;
    namespace operation {


        /**
         * An operation is a grouped set of 'things' we can do on a document
         * Only one operation can run at a time because the document needs to get locked
         * during a operaion.
         *
         * @param document
         */
        class DocumentOperation : public std::enable_shared_from_this<operation::DocumentOperation> {
                friend class lc::Document;

            public:
                DocumentOperation(std::shared_ptr<Document> document);
                std::shared_ptr<Document> document() const;

                /*!
                 * \brief execute this operation
                 */
                virtual void execute();

                virtual ~DocumentOperation() {}

            private:

                /**
                 * This function get's called when a operation starts and when the document is locked for you
                 * so you can do your work
                 */
                void process();
                /**
                 * This function will get called when the process of this operation starts
                 */
                virtual void start() const {};

                /**
                 * This function will get called when the process of this operation is finnished
                 */
                virtual void finnish() const {};

                std::shared_ptr<Document> _document;
            protected:
                /**
                 * This function get's called when a operation starts and when the document is locked for you
                 * so you can do your work
                 */
                virtual void processInternal() = 0;

        };
        using DocumentOperation_SPtr = std::shared_ptr<DocumentOperation>;
        using DocumentOperation_CSPtr = std::shared_ptr<const DocumentOperation>;
    }
}
// OPERATIONINTERFACE_H
