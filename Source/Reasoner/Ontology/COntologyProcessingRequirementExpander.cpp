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

#include "COntologyProcessingRequirementExpander.h"


namespace Konclude {

	namespace Reasoner {

		namespace Ontology {


			COntologyProcessingRequirementExpander::COntologyProcessingRequirementExpander() {
				COntologyProcessingStepVector* ontProStepVec = COntologyProcessingStepVector::getProcessingStepVectorInstance();
				mTriplesMappingOntProStepReq = new COntologyProcessingStepRequirement(ontProStepVec->getProcessingStep(COntologyProcessingStep::OPSTRIPLESMAPPING), COntologyProcessingStatus::PSCOMPLETELYYPROCESSED, 0, COntologyProcessingStatus::PSSUCESSFULL, 0);
				mActiveCountOntProStepReq = new COntologyProcessingStepRequirement(ontProStepVec->getProcessingStep(COntologyProcessingStep::OPSACTIVECOUNT), COntologyProcessingStatus::PSCOMPLETELYYPROCESSED, 0, COntologyProcessingStatus::PSSUCESSFULL, 0);
				mBuildOntProStepReq = new COntologyProcessingStepRequirement(ontProStepVec->getProcessingStep(COntologyProcessingStep::OPSBUILD), COntologyProcessingStatus::PSCOMPLETELYYPROCESSED, 0, COntologyProcessingStatus::PSSUCESSFULL, 0);
				mPreprocessOntProStepReq = new COntologyProcessingStepRequirement(ontProStepVec->getProcessingStep(COntologyProcessingStep::OPSPREPROCESS), COntologyProcessingStatus::PSCOMPLETELYYPROCESSED, 0, COntologyProcessingStatus::PSSUCESSFULL, 0);
				mTriplesIndexingOntProStepReq = new COntologyProcessingStepRequirement(ontProStepVec->getProcessingStep(COntologyProcessingStep::OPSTRIPLESINDEXING), COntologyProcessingStatus::PSCOMPLETELYYPROCESSED, 0, COntologyProcessingStatus::PSSUCESSFULL, 0);
				mConsistencyOntProStepReq = new COntologyProcessingStepRequirement(ontProStepVec->getProcessingStep(COntologyProcessingStep::OPSCONSISTENCY), COntologyProcessingStatus::PSCOMPLETELYYPROCESSED, 0, COntologyProcessingStatus::PSSUCESSFULL, 0);
				mIndividualOntProStepReq = new COntologyProcessingStepRequirement(ontProStepVec->getProcessingStep(COntologyProcessingStep::OPSPRECOMPUTEINDIVIDUAL), COntologyProcessingStatus::PSCOMPLETELYYPROCESSED, 0, COntologyProcessingStatus::PSSUCESSFULL, 0);
				mSaturationOntProStepReq = new COntologyProcessingStepRequirement(ontProStepVec->getProcessingStep(COntologyProcessingStep::OPSPRECOMPUTESATURATION), COntologyProcessingStatus::PSCOMPLETELYYPROCESSED, 0, COntologyProcessingStatus::PSSUCESSFULL, 0);
				mPrecomputeCyclesOntProStepReq = new COntologyProcessingStepRequirement(ontProStepVec->getProcessingStep(COntologyProcessingStep::OPSPRECOMPUTECYCLES), COntologyProcessingStatus::PSCOMPLETELYYPROCESSED, 0, COntologyProcessingStatus::PSSUCESSFULL, 0);
				mPrecomputeOccStatsOntProStepReq = new COntologyProcessingStepRequirement(ontProStepVec->getProcessingStep(COntologyProcessingStep::OPSPRECOMPUTEOCCURRENCESTATISTICS), COntologyProcessingStatus::PSCOMPLETELYYPROCESSED, 0, COntologyProcessingStatus::PSSUCESSFULL, 0);
				mClassClassifyOntProStepReq = new COntologyProcessingStepRequirement(ontProStepVec->getProcessingStep(COntologyProcessingStep::OPSCLASSCLASSIFY), COntologyProcessingStatus::PSCOMPLETELYYPROCESSED, 0, COntologyProcessingStatus::PSSUCESSFULL, 0);
				mObjPropClassifyOntProStepReq = new COntologyProcessingStepRequirement(ontProStepVec->getProcessingStep(COntologyProcessingStep::OPSOBJECTROPERTYCLASSIFY), COntologyProcessingStatus::PSCOMPLETELYYPROCESSED, 0, COntologyProcessingStatus::PSSUCESSFULL, 0);
				mDataPropClassifyOntProStepReq = new COntologyProcessingStepRequirement(ontProStepVec->getProcessingStep(COntologyProcessingStep::OPSDATAROPERTYCLASSIFY), COntologyProcessingStatus::PSCOMPLETELYYPROCESSED, 0, COntologyProcessingStatus::PSSUCESSFULL, 0);
				mRequiredConsistencyOntProStepReq = new COntologyProcessingStepRequirement(ontProStepVec->getProcessingStep(COntologyProcessingStep::OPSCONSISTENCY), COntologyProcessingStatus::PSCOMPLETELYYPROCESSED, 0, COntologyProcessingStatus::PSSUCESSFULL, COntologyProcessingStatus::PSINCONSITENT);
				mInitRealizeOntProStepReq = new COntologyProcessingStepRequirement(ontProStepVec->getProcessingStep(COntologyProcessingStep::OPSINITREALIZE), COntologyProcessingStatus::PSCOMPLETELYYPROCESSED, 0, COntologyProcessingStatus::PSSUCESSFULL, 0);
				mConceptRealizeOntProStepReq = new COntologyProcessingStepRequirement(ontProStepVec->getProcessingStep(COntologyProcessingStep::OPSCONCEPTREALIZE), COntologyProcessingStatus::PSCOMPLETELYYPROCESSED, 0, COntologyProcessingStatus::PSSUCESSFULL, 0);
				mSameIndividualsRealizeOntProStepReq = new COntologyProcessingStepRequirement(ontProStepVec->getProcessingStep(COntologyProcessingStep::OPSSAMEINDIVIDUALSREALIZE), COntologyProcessingStatus::PSCOMPLETELYYPROCESSED, 0, COntologyProcessingStatus::PSSUCESSFULL, 0);
				mRoleRealizeOntProStepReq = new COntologyProcessingStepRequirement(ontProStepVec->getProcessingStep(COntologyProcessingStep::OPSROLEREALIZE), COntologyProcessingStatus::PSCOMPLETELYYPROCESSED, 0, COntologyProcessingStatus::PSSUCESSFULL, 0);
				mComplexQueryAnsweringOntProStepReq = new COntologyProcessingStepRequirement(ontProStepVec->getProcessingStep(COntologyProcessingStep::OPSANSWERCOMPLEXQUERY), COntologyProcessingStatus::PSCOMPLETELYYPROCESSED, 0, COntologyProcessingStatus::PSSUCESSFULL, 0);
			}

			COntologyProcessingRequirementExpander::~COntologyProcessingRequirementExpander() {
				delete mTriplesIndexingOntProStepReq;
				delete mTriplesMappingOntProStepReq;
				delete mActiveCountOntProStepReq;
				delete mBuildOntProStepReq;
				delete mPreprocessOntProStepReq;
				delete mConsistencyOntProStepReq;
				delete mIndividualOntProStepReq;
				delete mSaturationOntProStepReq;
				delete mInitRealizeOntProStepReq;
				delete mPrecomputeCyclesOntProStepReq;
				delete mPrecomputeOccStatsOntProStepReq;
				delete mClassClassifyOntProStepReq;
				delete mObjPropClassifyOntProStepReq;
				delete mDataPropClassifyOntProStepReq;
				delete mRequiredConsistencyOntProStepReq;
				delete mConceptRealizeOntProStepReq;
				delete mRoleRealizeOntProStepReq;
				delete mSameIndividualsRealizeOntProStepReq;
				delete mComplexQueryAnsweringOntProStepReq;
			}


			const QList<COntologyProcessingRequirement*> COntologyProcessingRequirementExpander::getUnsatisfiedRequirementsExpanded(const QList<COntologyProcessingRequirement*>& requirements, CConcreteOntology* ontology) {
				QList<COntologyProcessingRequirement*> mActualReqList;
				QList<COntologyProcessingRequirement*> mCheckReqList;
				QSet<COntologyProcessingRequirement*> mCheckReqSet;

				for (QList<COntologyProcessingRequirement*>::const_iterator it = requirements.constBegin(), itEnd = requirements.constEnd(); it != itEnd; ++it) {
					COntologyProcessingRequirement* requirement = *it;
					if (!mCheckReqSet.contains(requirement)) {
						mCheckReqSet.insert(requirement);
						mCheckReqList.append(requirement);
					}
				}

				while (!mCheckReqList.isEmpty()) {
					COntologyProcessingRequirement* requirement = mCheckReqList.takeFirst();
					if (!requirement->isRequirementSatisfied(ontology)) {
						COntologyProcessingStepRequirement* reqProStep = dynamic_cast<COntologyProcessingStepRequirement*>(requirement);
						if (reqProStep) {
							COntologyProcessingStep* proStep = reqProStep->getRequiredProcessingStep();
							if (proStep) {
								QList<COntologyProcessingRequirement*>* additionalRequirements = proStep->getProcessingRequirementList();
								for (QList<COntologyProcessingRequirement*>::const_iterator it = additionalRequirements->constBegin(), itEnd = additionalRequirements->constEnd(); it != itEnd; ++it) {
									COntologyProcessingRequirement* additionalRequirement = *it;
									if (!mCheckReqSet.contains(additionalRequirement)) {
										mCheckReqSet.insert(additionalRequirement);
										mCheckReqList.append(additionalRequirement);
									}
								}
							}
						}
						mActualReqList.append(requirement);
					}
				}
				return mActualReqList;
			}


			COntologyProcessingStepRequirement* COntologyProcessingRequirementExpander::getRequiredConsistencyOntologyProcessingStepRequirement() {
				return mRequiredConsistencyOntProStepReq;
			}


			COntologyProcessingStepRequirement* COntologyProcessingRequirementExpander::getRequiredIndividualPrecomputationOntologyProcessingStepRequirement() {
				return mIndividualOntProStepReq;
			}

			COntologyProcessingStepRequirement* COntologyProcessingRequirementExpander::getCompletedDefaultOntologyProcessingStepRequirement(COntologyProcessingStep::PROCESSINGSTEPTYPE processingStep) {
				COntologyProcessingStepRequirement* ontProStepReq = nullptr;
				if (processingStep == COntologyProcessingStep::OPSTRIPLESMAPPING) {
					ontProStepReq = mTriplesMappingOntProStepReq;
				} else if (processingStep == COntologyProcessingStep::OPSACTIVECOUNT) {
					ontProStepReq = mActiveCountOntProStepReq;
				} else if(processingStep == COntologyProcessingStep::OPSBUILD) {
					ontProStepReq = mBuildOntProStepReq;
				} else if (processingStep == COntologyProcessingStep::OPSPREPROCESS) {
					ontProStepReq = mPreprocessOntProStepReq;
				} else if (processingStep == COntologyProcessingStep::OPSTRIPLESINDEXING) {
					ontProStepReq = mTriplesIndexingOntProStepReq;
				} else if (processingStep == COntologyProcessingStep::OPSCONSISTENCY) {
					ontProStepReq = mConsistencyOntProStepReq;
				} else if (processingStep == COntologyProcessingStep::OPSPRECOMPUTEINDIVIDUAL) {
					ontProStepReq = mIndividualOntProStepReq;
				} else if (processingStep == COntologyProcessingStep::OPSPRECOMPUTESATURATION) {
					ontProStepReq = mSaturationOntProStepReq;
				} else if (processingStep == COntologyProcessingStep::OPSPRECOMPUTECYCLES) {
					ontProStepReq = mPrecomputeCyclesOntProStepReq;
				} else if (processingStep == COntologyProcessingStep::OPSPRECOMPUTEOCCURRENCESTATISTICS) {
					ontProStepReq = mPrecomputeOccStatsOntProStepReq;
				} else if (processingStep == COntologyProcessingStep::OPSCLASSCLASSIFY) {
					ontProStepReq = mClassClassifyOntProStepReq;
				} else if (processingStep == COntologyProcessingStep::OPSOBJECTROPERTYCLASSIFY) {
					ontProStepReq = mObjPropClassifyOntProStepReq;
				} else if (processingStep == COntologyProcessingStep::OPSDATAROPERTYCLASSIFY) {
					ontProStepReq = mDataPropClassifyOntProStepReq;
				} else if (processingStep == COntologyProcessingStep::OPSINITREALIZE) {
					ontProStepReq = mInitRealizeOntProStepReq;
				} else if (processingStep == COntologyProcessingStep::OPSCONCEPTREALIZE) {
					ontProStepReq = mConceptRealizeOntProStepReq;
				} else if (processingStep == COntologyProcessingStep::OPSROLEREALIZE) {
					ontProStepReq = mRoleRealizeOntProStepReq;
				} else if (processingStep == COntologyProcessingStep::OPSSAMEINDIVIDUALSREALIZE) {
					ontProStepReq = mSameIndividualsRealizeOntProStepReq;
				} else if (processingStep == COntologyProcessingStep::OPSANSWERCOMPLEXQUERY) {
					ontProStepReq = mComplexQueryAnsweringOntProStepReq;
				}
				return ontProStepReq;
			}

		}; // end namespace Ontology

	}; // end namespace Reasoner

}; // end namespace Konclude
