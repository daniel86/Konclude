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

#ifndef KONCLUDE_REASONER_ANSWERER_CCONFIGURATIONANSWERINGHANDLERFACTORY_H
#define KONCLUDE_REASONER_ANSWERER_CCONFIGURATIONANSWERINGHANDLERFACTORY_H

// Libraries includes


// Namespace includes
#include "AnswererSettings.h"
#include "CAnsweringHandler.h"
#include "CAnsweringHandlerFactory.h"
#include "COptimizedComplexExpressionAnsweringHandler.h"
#include "COptimizedComplexCompositionOntologyAnsweringItem.h"
#include "COptimizedComplexCompositionRedlandRasqalAnsweringHandler.h"


// Other includes
#include "Reasoner/Query/CComplexAnsweringQuery.h"

#include "Config/CConfiguration.h"
#include "Config/CConfigDataReader.h"


// Logger includes
#include "Logger/CLogger.h"
#include "Logger/CLogIdentifier.h"





namespace Konclude {

	using namespace Config;

	namespace Reasoner {

		using namespace Query;

		namespace Answerer {



			/*! 
			 *
			 *		\class		CConfigurationAnsweringHandlerFactory
			 *		\author		Andreas Steigmiller
			 *		\version	0.1
			 *		\brief		TODO
			 *
			 */
			class CConfigurationAnsweringHandlerFactory : public CAnsweringHandlerFactory {
				// public methods
				public:
					//! Constructor
					CConfigurationAnsweringHandlerFactory(CConfiguration* config);

					//! Destructor
					virtual ~CConfigurationAnsweringHandlerFactory();


					virtual CAnsweringHandler* createAnsweringHandler(CConcreteOntology* ontology, bool composedQuery);



				// protected methods
				protected:

				// protected variables
				protected:
					CConfiguration* mConfig;


				// private methods
				private:

				// private variables
				private:

			};

		}; // end namespace Answerer

	}; // end namespace Reasoner

}; // end namespace Konclude

#endif // KONCLUDE_REASONER_ANSWERER_CCONFIGURATIONANSWERINGHANDLERFACTORY_H
