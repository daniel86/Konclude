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

#include "CQueryGetFlattenedTypesExpression.h"


namespace Konclude {

	namespace Parser {

		namespace Expression {


			CQueryGetFlattenedTypesExpression::CQueryGetFlattenedTypesExpression(const QString& name, bool direct, CIndividualTermExpression* individualTermExp) 
					: CNameAssociator(name),CIndividualTermExpressionAssociator(individualTermExp),mDirect(direct) {
			}


			CQueryGetFlattenedTypesExpression::~CQueryGetFlattenedTypesExpression() {
			}


			CBuildExpression::ExpressionType CQueryGetFlattenedTypesExpression::getType() {
				return BETGETFLATTENEDTYPES;
			}


			cint64 CQueryGetFlattenedTypesExpression::getStructuralHashValue() {
				cint64 hashValue = CExpressionHashMixer::getHashValueMixed((cint64)getType(),CIndividualTermExpressionAssociator::getStructuralHashValue(),(cint64)mDirect);
				return hashValue;
			}

			bool CQueryGetFlattenedTypesExpression::compareStructuralEquivalence(CBuildExpression* compareExpression) {
				CQueryGetFlattenedTypesExpression* compExpCast = dynamic_cast<CQueryGetFlattenedTypesExpression*>(compareExpression);
				if (!compExpCast) {
					return false;
				} 
				if (compExpCast->mDirect != mDirect) {
					return false;
				}
				return CIndividualTermExpressionAssociator::compareStructuralEquivalence(*compExpCast);
			}

			bool CQueryGetFlattenedTypesExpression::isDirect() {
				return mDirect;
			}

			bool CQueryGetFlattenedTypesExpression::visitSubExpressions(CSubExpressionVisitor* subExpressionVisitor) {
				if (subExpressionVisitor) {
					CIndividualTermExpressionAssociator::visitSubExpressions(this,subExpressionVisitor);
					return true;
				}
				return false;
			}

		}; // end namespace Expression

	}; // end namespace Parser

}; // end namespace Konclude
