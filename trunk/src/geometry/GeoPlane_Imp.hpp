// *****************************************************************************
// <ProjectName> ENigMA </ProjectName>
// <Description> Extended Numerical Multiphysics Analysis </Description>
// <HeadURL> $HeadURL$ </HeadURL>
// <LastChangedDate> $LastChangedDate$ </LastChangedDate>
// <LastChangedRevision> $LastChangedRevision$ </LastChangedRevision>
// <Author> Billy Araujo </Author>
// <Copyright> Copyright (c) 2012, All Rights Reserved </Copyright>
// *****************************************************************************

// <ProjectName> $ProjectName$ </ProjectName>

#pragma once

namespace ENigMA
{

    namespace geometry
    {

        template <typename Real>
        CGeoPlane<Real>::CGeoPlane()
        {

        }

        template <typename Real>
        CGeoPlane<Real>::CGeoPlane(CGeoNormal<Real>& aNormal, const Real d) 
        {

            this->set(aNormal, d);

        }

        template <typename Real>
        void CGeoPlane<Real>::set(CGeoNormal<Real>& aNormal, const Real d) 
        {

            m_normal = aNormal;
            m_d = d;

        }

        template <typename Real>
        CGeoPlane<Real>::~CGeoPlane()
        {

        }

        template <typename Real>
        CGeoNormal<Real>& CGeoPlane<Real>::normal()
        {

            return m_normal;

        }

        template <typename Real>
        void CGeoPlane<Real>::setD(const Real aValue)
        {
            
            m_d = aValue;

        }

        template <typename Real>
        Real CGeoPlane<Real>::d() const
        {

            return m_d;

        }

        template <typename Real>
        void CGeoPlane<Real>::invert()
        {

            m_normal *= -1;
            m_d *= -1;

        };

        template <typename Real>
        bool CGeoPlane<Real>::distance(const CGeoCoordinate<Real>& aPoint, CGeoCoordinate<Real>& aNewPoint, Real& aDistance, const Real aTolerance)
        {

            Real s = this->normal().dot(aPoint) + this->d();

            aNewPoint = aPoint + this->normal() * s;

            aDistance = fabs(s);

            return true;

        }

    }

}