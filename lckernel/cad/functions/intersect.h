#pragma once

#include "cad/base/cadentity.h"
#include "cad/geometry/geocoordinate.h"
#include "cad/interface/entityvisitor.h"
#include <vector>

namespace lc {

    /**
      * @brief calculate the intersection pojnts of 2 entities
      * @sa IntersectMany
      */
    class Intersect : public EntityVisitor {
        public:
            enum Method {
                OnPath = 0,     // means that the paths must intersect
                Any = 1       // means that the paths may intersect outside of the real path.
                      // For example two lines of 2 in a slight angle might intersect outside of line's coordinate
                      // When method == Any is selected, the system will return that coordinate
                      // When Intersect is selected only a point is returned for a actual cross point
            };

            Intersect(Method method, double tolerance);
            virtual void visit(const geo::Vector&, const geo::Vector&);

            virtual void visit(Line_CSPtr, const geo::Vector&);
            virtual void visit(Line_CSPtr, Point_CSPtr);
            virtual void visit(Line_CSPtr, Line_CSPtr);
            virtual void visit(Line_CSPtr, Circle_CSPtr);
            virtual void visit(Line_CSPtr, Arc_CSPtr);
            virtual void visit(Line_CSPtr, Ellipse_CSPtr);
            virtual void visit(Line_CSPtr, Text_CSPtr);
            virtual void visit(Line_CSPtr, Spline_CSPtr);
            virtual void visit(Line_CSPtr, MText_CSPtr);
            virtual void visit(Line_CSPtr, DimAligned_CSPtr);
            virtual void visit(Line_CSPtr, DimAngular_CSPtr);
            virtual void visit(Line_CSPtr, DimDiametric_CSPtr);
            virtual void visit(Line_CSPtr, DimLinear_CSPtr);
            virtual void visit(Line_CSPtr, DimRadial_CSPtr);

            virtual void visit(Point_CSPtr, const geo::Vector&);
            virtual void visit(Point_CSPtr, Point_CSPtr);
            virtual void visit(Point_CSPtr, Line_CSPtr);
            virtual void visit(Point_CSPtr, Circle_CSPtr);
            virtual void visit(Point_CSPtr, Arc_CSPtr);
            virtual void visit(Point_CSPtr, Ellipse_CSPtr);
            virtual void visit(Point_CSPtr, Text_CSPtr);
            virtual void visit(Point_CSPtr, Spline_CSPtr);
            virtual void visit(Point_CSPtr, MText_CSPtr);
            virtual void visit(Point_CSPtr, DimAligned_CSPtr);
            virtual void visit(Point_CSPtr, DimAngular_CSPtr);
            virtual void visit(Point_CSPtr, DimDiametric_CSPtr);
            virtual void visit(Point_CSPtr, DimLinear_CSPtr);
            virtual void visit(Point_CSPtr, DimRadial_CSPtr);

            virtual void visit(Circle_CSPtr, const geo::Vector&);
            virtual void visit(Circle_CSPtr, Point_CSPtr);
            virtual void visit(Circle_CSPtr, Line_CSPtr);
            virtual void visit(Circle_CSPtr, Circle_CSPtr);
            virtual void visit(Circle_CSPtr, Arc_CSPtr);
            virtual void visit(Circle_CSPtr, Ellipse_CSPtr);
            virtual void visit(Circle_CSPtr, Text_CSPtr);
            virtual void visit(Circle_CSPtr, Spline_CSPtr);
            virtual void visit(Circle_CSPtr, MText_CSPtr);
            virtual void visit(Circle_CSPtr, DimAligned_CSPtr);
            virtual void visit(Circle_CSPtr, DimAngular_CSPtr);
            virtual void visit(Circle_CSPtr, DimDiametric_CSPtr);
            virtual void visit(Circle_CSPtr, DimLinear_CSPtr);
            virtual void visit(Circle_CSPtr, DimRadial_CSPtr);


            virtual void visit(Arc_CSPtr, const geo::Vector&);
            virtual void visit(Arc_CSPtr, Point_CSPtr);
            virtual void visit(Arc_CSPtr, Line_CSPtr);
            virtual void visit(Arc_CSPtr, Circle_CSPtr);
            virtual void visit(Arc_CSPtr, Arc_CSPtr);
            virtual void visit(Arc_CSPtr, Ellipse_CSPtr);
            virtual void visit(Arc_CSPtr, Text_CSPtr);
            virtual void visit(Arc_CSPtr, Spline_CSPtr);
            virtual void visit(Arc_CSPtr, MText_CSPtr);
            virtual void visit(Arc_CSPtr, DimAligned_CSPtr);
            virtual void visit(Arc_CSPtr, DimAngular_CSPtr);
            virtual void visit(Arc_CSPtr, DimDiametric_CSPtr);
            virtual void visit(Arc_CSPtr, DimLinear_CSPtr);
            virtual void visit(Arc_CSPtr, DimRadial_CSPtr);

            virtual void visit(Ellipse_CSPtr, const geo::Vector&);
            virtual void visit(Ellipse_CSPtr, Point_CSPtr);
            virtual void visit(Ellipse_CSPtr, Line_CSPtr);
            virtual void visit(Ellipse_CSPtr, Circle_CSPtr);
            virtual void visit(Ellipse_CSPtr, Arc_CSPtr);
            virtual void visit(Ellipse_CSPtr, Ellipse_CSPtr);
            virtual void visit(Ellipse_CSPtr, Text_CSPtr);
            virtual void visit(Ellipse_CSPtr, Spline_CSPtr);
            virtual void visit(Ellipse_CSPtr, MText_CSPtr);
            virtual void visit(Ellipse_CSPtr, DimAligned_CSPtr);
            virtual void visit(Ellipse_CSPtr, DimAngular_CSPtr);
            virtual void visit(Ellipse_CSPtr, DimDiametric_CSPtr);
            virtual void visit(Ellipse_CSPtr, DimLinear_CSPtr);
            virtual void visit(Ellipse_CSPtr, DimRadial_CSPtr);

            virtual void visit(Spline_CSPtr, const geo::Vector&);
            virtual void visit(Spline_CSPtr, Point_CSPtr);
            virtual void visit(Spline_CSPtr, Line_CSPtr);
            virtual void visit(Spline_CSPtr, Circle_CSPtr);
            virtual void visit(Spline_CSPtr, Arc_CSPtr);
            virtual void visit(Spline_CSPtr, Ellipse_CSPtr);
            virtual void visit(Spline_CSPtr, Text_CSPtr);
            virtual void visit(Spline_CSPtr, Spline_CSPtr);
            virtual void visit(Spline_CSPtr, MText_CSPtr);
            virtual void visit(Spline_CSPtr, DimAligned_CSPtr);
            virtual void visit(Spline_CSPtr, DimAngular_CSPtr);
            virtual void visit(Spline_CSPtr, DimDiametric_CSPtr);
            virtual void visit(Spline_CSPtr, DimLinear_CSPtr);
            virtual void visit(Spline_CSPtr, DimRadial_CSPtr);

            virtual void visit(DimAligned_CSPtr, const geo::Vector&);
            virtual void visit(DimAligned_CSPtr, Point_CSPtr);
            virtual void visit(DimAligned_CSPtr, Line_CSPtr);
            virtual void visit(DimAligned_CSPtr, Circle_CSPtr);
            virtual void visit(DimAligned_CSPtr, Arc_CSPtr);
            virtual void visit(DimAligned_CSPtr, Ellipse_CSPtr);
            virtual void visit(DimAligned_CSPtr, Text_CSPtr);
            virtual void visit(DimAligned_CSPtr, Spline_CSPtr);
            virtual void visit(DimAligned_CSPtr, MText_CSPtr);
            virtual void visit(DimAligned_CSPtr, DimAligned_CSPtr);
            virtual void visit(DimAligned_CSPtr, DimAngular_CSPtr);
            virtual void visit(DimAligned_CSPtr, DimDiametric_CSPtr);
            virtual void visit(DimAligned_CSPtr, DimLinear_CSPtr);
            virtual void visit(DimAligned_CSPtr, DimRadial_CSPtr);

            virtual void visit(DimAngular_CSPtr, const geo::Vector&);
            virtual void visit(DimAngular_CSPtr, Point_CSPtr);
            virtual void visit(DimAngular_CSPtr, Line_CSPtr);
            virtual void visit(DimAngular_CSPtr, Circle_CSPtr);
            virtual void visit(DimAngular_CSPtr, Arc_CSPtr);
            virtual void visit(DimAngular_CSPtr, Ellipse_CSPtr);
            virtual void visit(DimAngular_CSPtr, Text_CSPtr);
            virtual void visit(DimAngular_CSPtr, Spline_CSPtr);
            virtual void visit(DimAngular_CSPtr, MText_CSPtr);
            virtual void visit(DimAngular_CSPtr, DimAligned_CSPtr);
            virtual void visit(DimAngular_CSPtr, DimAngular_CSPtr);
            virtual void visit(DimAngular_CSPtr, DimDiametric_CSPtr);
            virtual void visit(DimAngular_CSPtr, DimLinear_CSPtr);
            virtual void visit(DimAngular_CSPtr, DimRadial_CSPtr);

            virtual void visit(DimDiametric_CSPtr, const geo::Vector&);
            virtual void visit(DimDiametric_CSPtr, Point_CSPtr);
            virtual void visit(DimDiametric_CSPtr, Line_CSPtr);
            virtual void visit(DimDiametric_CSPtr, Circle_CSPtr);
            virtual void visit(DimDiametric_CSPtr, Arc_CSPtr);
            virtual void visit(DimDiametric_CSPtr, Ellipse_CSPtr);
            virtual void visit(DimDiametric_CSPtr, Text_CSPtr);
            virtual void visit(DimDiametric_CSPtr, Spline_CSPtr);
            virtual void visit(DimDiametric_CSPtr, MText_CSPtr);
            virtual void visit(DimDiametric_CSPtr, DimAligned_CSPtr);
            virtual void visit(DimDiametric_CSPtr, DimAngular_CSPtr);
            virtual void visit(DimDiametric_CSPtr, DimDiametric_CSPtr);
            virtual void visit(DimDiametric_CSPtr, DimLinear_CSPtr);
            virtual void visit(DimDiametric_CSPtr, DimRadial_CSPtr);

            virtual void visit(DimLinear_CSPtr, const geo::Vector&);
            virtual void visit(DimLinear_CSPtr, Point_CSPtr);
            virtual void visit(DimLinear_CSPtr, Line_CSPtr);
            virtual void visit(DimLinear_CSPtr, Circle_CSPtr);
            virtual void visit(DimLinear_CSPtr, Arc_CSPtr);
            virtual void visit(DimLinear_CSPtr, Ellipse_CSPtr);
            virtual void visit(DimLinear_CSPtr, Text_CSPtr);
            virtual void visit(DimLinear_CSPtr, Spline_CSPtr);
            virtual void visit(DimLinear_CSPtr, MText_CSPtr);
            virtual void visit(DimLinear_CSPtr, DimAligned_CSPtr);
            virtual void visit(DimLinear_CSPtr, DimAngular_CSPtr);
            virtual void visit(DimLinear_CSPtr, DimDiametric_CSPtr);
            virtual void visit(DimLinear_CSPtr, DimLinear_CSPtr);
            virtual void visit(DimLinear_CSPtr, DimRadial_CSPtr);

            virtual void visit(DimRadial_CSPtr, const geo::Vector&);
            virtual void visit(DimRadial_CSPtr, Point_CSPtr);
            virtual void visit(DimRadial_CSPtr, Line_CSPtr);
            virtual void visit(DimRadial_CSPtr, Circle_CSPtr);
            virtual void visit(DimRadial_CSPtr, Arc_CSPtr);
            virtual void visit(DimRadial_CSPtr, Ellipse_CSPtr);
            virtual void visit(DimRadial_CSPtr, Text_CSPtr);
            virtual void visit(DimRadial_CSPtr, Spline_CSPtr);
            virtual void visit(DimRadial_CSPtr, MText_CSPtr);
            virtual void visit(DimRadial_CSPtr, DimAligned_CSPtr);
            virtual void visit(DimRadial_CSPtr, DimAngular_CSPtr);
            virtual void visit(DimRadial_CSPtr, DimDiametric_CSPtr);
            virtual void visit(DimRadial_CSPtr, DimLinear_CSPtr);
            virtual void visit(DimRadial_CSPtr, DimRadial_CSPtr);

            std::vector<geo::Coordinate> result() const;
            void insert(Quadratic const &q1 , Quadratic const &q2);
        private:
            std::vector<geo::Coordinate> _intersectionPoints;
            const Method _method;
            const double _tolerance;
    };

    /**
      * @brief calculate intersection points of many entities
      * @note Can we make this into a general template ???
      * @sa Intersect
      */
    class IntersectMany {
        public:
            IntersectMany(std::vector<CADEntity_CSPtr>,  Intersect::Method, double tolerance);
            std::vector<geo::Coordinate> result() const;
        private:
            std::vector<CADEntity_CSPtr> _entities;
            const Intersect::Method _method;
            const double _tolerance;
    };

    /**
      * @brief calculate intersection points of many entities
      * @note Can we make this into a general template ???
      * @sa Intersect
      */
    class IntersectAgainstOthers {
        public:
            IntersectAgainstOthers(std::vector<CADEntity_CSPtr>,  std::vector<CADEntity_CSPtr>, Intersect::Method, double tolerance);
            std::vector<geo::Coordinate> result() const;
        private:
            std::vector<CADEntity_CSPtr> _entities;
            std::vector<CADEntity_CSPtr> _others;
            const Intersect::Method _method;
            const double _tolerance;
    };

    /**
      * @brief calculate intersection points of many entities but beal out asap when a intersection point was found
      * @note Can we make this into a general template ???
      * @sa Intersect
      */
    class HasIntersectAgainstOthers {
        public:
            HasIntersectAgainstOthers(std::vector<CADEntity_CSPtr>,  std::vector<CADEntity_CSPtr>, Intersect::Method, double tolerance);
            bool result() const;
        private:
            std::vector<CADEntity_CSPtr> _entities;
            std::vector<CADEntity_CSPtr> _others;
            const Intersect::Method _method;
            const double _tolerance;
    };

}
