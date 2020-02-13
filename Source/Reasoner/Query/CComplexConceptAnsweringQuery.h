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

#ifndef KONCLUDE_REASONER_QUERY_CCOMPLEXCONCEPTANSWERINGQUERY_H
#define KONCLUDE_REASONER_QUERY_CCOMPLEXCONCEPTANSWERINGQUERY_H

// Libraries includes


// Namespace includes
#include "CComplexAnsweringExpressionQuery.h"


// Other includes
#include "Reasoner/Ontology/CConcreteOntology.h"

#include "Config/CConfigurationBase.h"

// Logger includes
#include "Logger/CLogger.h"



namespace Konclude {

	using namespace Config;

	namespace Reasoner {

		using namespace Ontology;

		namespace Query {

			/*! 
			 *
			 *		\class		CComplexConceptAnsweringQuery
			 *		\author		Andreas Steigmiller
			 *		\version	0.1
			 *		\brief		TODO
			 *
			 */
			class CComplexConceptAnsweringQuery : public CComplexAnsweringExpressionQuery {
				// public methods
				public:
					//! Constructor
					CComplexConceptAnsweringQuery(CConcreteOntology* baseOntology, CConcreteOntology* expressionOntology, CConfigurationBase* configuration, const QString& queryName);

					//! Destructor
					virtual ~CComplexConceptAnsweringQuery();



					CBuildExpression* getExpressionOfInterest();

					bool isSuperClassNodesComputationRequired();
					bool isSubClassNodesComputationRequired();
					bool isEquivalentClassNodesComputationRequired();
					bool isInstancesComputationRequired();
					bool isSatisfiableComputationRequired();

					bool isDirect();
					bool isFlattened();

					CComplexConceptAnsweringQuery* setDirect(bool direct);
					CComplexConceptAnsweringQuery* setFlattened(bool flattened);


				// protected methods
				protected:

				// protected variables
				protected:
					CBuildExpression* mExpressionOfInterest;

					bool mSuperClassNodesRequired;
					bool mSubClassNodesRequired;
					bool mEquivalentClassNodesRequired;
					bool mInstancesRequired;
					bool mSatisfiableRequired;

					bool mDirect;
					bool mFlattened;


				// private methods
				private:

				// private variables
				private:

			};

		}; // end namespace Query

	}; // end namespace Reasoner

}; // end namespace Konclude

#endif // KONCLUDE_REASONER_QUERY_CCOMPLEXCONCEPTANSWERINGQUERY_H
