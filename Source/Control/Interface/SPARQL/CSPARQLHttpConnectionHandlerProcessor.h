/*
 *		Copyright (C) 2013-2015, 2019 by the Konclude Developer Team.
 *
 *		This file is part of the reasoning system Konclude.
 *		For details and support, see <http://konclude.com/>.
 *
 *		Konclude is free software: you can redistribute it and/or modify
 *		it under the terms of version 3 of the GNU Lesser General Public
 *		License (LGPLv3) as published by the Free Software Foundation.
 *
 *		Konclude is distributed in the hope that it will be useful,
 *		but WITHOUT ANY WARRANTY; without even the implied warranty of
 *		MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *		GNU (Lesser) General Public License for more details.
 *
 *		You should have received a copy of the GNU (Lesser) General Public
 *		License along with Konclude. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef KONCLUDE_CONTROL_INTERFACE_SPARQL_CSPARQLHTTPCONNECTIONHANDLERPROCESSOR_H
#define KONCLUDE_CONTROL_INTERFACE_SPARQL_CSPARQLHTTPCONNECTIONHANDLERPROCESSOR_H

// Libraries includes
#include <QTcpSocket>
#include <QHostAddress>
#include <QAtomicInt>

// Namespace includes
#include "SPARQLSettings.h"
#include "CSPARQLRecordResultStreamingInterpreter.h"
#include "CSPARQLStreamingWriter.h"

// Other includes
#include "Control/Interface/SPARQL/Events/CResultStreamingWriteEvent.h"

#include "Network/HTTP/CQtHttpPooledConnectionHandler.h"
#include "Network/HTTP/CQtHttpRequestBodyOnlyParser.h"
#include "Network/HTTP/CQtHttpConnectionHandlerReleaser.h"

#include "Network/HTTP/Events/CHandleIncomingHttpConnectionEvent.h"
#include "Network/HTTP/Events/CConnectionReadyReadEvent.h"
#include "Network/HTTP/Events/CConnectionDisconnectedEvent.h"

#include "Control/Interface/OWLlink/COWLlinkProcessor.h"


#include "Control/Command/CConfigManagerReader.h"

// Logger includes
#include "Logger/CLogger.h"
#include "Logger/CLogIdentifier.h"


namespace Konclude {

	using namespace Network::HTTP;
	using namespace Network::HTTP::Events;

	namespace Control {

		using namespace Command;

		namespace Interface {

			using namespace OWLlink;

			namespace SPARQL {

				using namespace Events;


				/*! 
				 *
				 *		\class		CSPARQLHttpConnectionHandlerProcessor
				 *		\author		Andreas Steigmiller
				 *		\version	0.1
				 *		\brief		TODO
				 *
				 */
				class CSPARQLHttpConnectionHandlerProcessor : public COWLlinkProcessor, public CQtHttpPooledConnectionHandler, public CSPARQLStreamingWriter {
					Q_OBJECT

					// public methods
					public:
						//! Constructor
						CSPARQLHttpConnectionHandlerProcessor(CConfiguration* loaderConfig, CQtHttpConnectionHandlerReleaser* releaser);

						//! Destructor
						virtual ~CSPARQLHttpConnectionHandlerProcessor();

						virtual bool handleIncomingConnection(int socketDescriptor);


						bool isHandlerQueued();
						CSPARQLHttpConnectionHandlerProcessor* setHandlerQueued(bool queued);

						virtual bool writeStreamData(const QList<CSPARQLResultBufferWriteData>& bufferList, bool last);
						virtual CSPARQLStreamingWriter* writeStreamDataToSocket(QList<CSPARQLResultBufferWriteData>* bufferList, bool last);

					// protected methods
					protected:
						virtual void threadStarted();
						virtual void threadStopped();

						bool processCustomsEvents(QEvent::Type type, CCustomEvent *event);

						virtual COWLlinkProcessor* initializeOWLlinkContent();
						virtual COWLlinkProcessor* concludeOWLlinkContent();


						virtual COWLlinkProcessor* sendData(const QByteArray& dataString);

						virtual CConfiguration *getConfiguration();


						CSPARQLStreamingWriter* writeChunk(const QByteArray& byteArray);

					// protected variables
					protected:


					// private methods
					private:
						QTcpSocket* mSocket;
						CQtHttpRequestBodyOnlyParser* mParser;

						bool mProcessingRequest;
						bool mProcessMoreRead;
						QByteArray* mProcessingByteArray;

						CSPARQLRecordResultStreamingInterpreter* mSPARQLInterpreter;
						bool mWritingStarted;
						bool mDataWritten;
						bool mWritingFailed;
						CCommand* mProcessingCommand;

						CConfiguration* mLoaderConfig;
						QSemaphore mThreadStartedSemaphore;

						CQtHttpConnectionHandlerReleaser* mReleaser;
						bool mQueued;
						bool mForceDisconnect;
						bool mThreadedWriting;

						cint64 mChunkPart;
						CPreconditionSynchronizer* mOriginPreSynchronizer;


						QByteArray mStreamSPARQLHeader;
						QByteArray mStreamSPARQLFooter;

						QSemaphore* mWriteLimitSemaphore;
						QSemaphore* mWrittenContinueSemaphore;
						bool mBlockingWarned;


					// private slots
					private slots:
						void connectionRead();
						void connectionDisconnect();

					// private variables
					private:

				};

			}; // end namespace SPARQL 

		}; // end namespace Interface

	}; // end namespace Control

}; // end namespace Konclude

#endif // KONCLUDE_CONTROL_INTERFACE_SPARQL_CSPARQLHTTPCONNECTIONHANDLERPROCESSOR_H
