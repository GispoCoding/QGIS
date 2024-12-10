/***************************************************************************
                          qgsgeometryoptions.h
                             -------------------
    begin                : Aug 23, 2018
    copyright            : (C) 2018 by Matthias Kuhn
    email                : matthias@opengis.ch
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef QGSGEOMETRYOPTIONS_H
#define QGSGEOMETRYOPTIONS_H

#include "qgis_core.h"
#include "qgsgeometry.h"

#include <QObject>

class QgsSettingsEntryString;

/**
 * \ingroup core
 *
 * \brief The QgsGeometryOptions class contains options to automatically adjust geometries to
 * constraints on a layer.
 *
 * \since QGIS 3.4
 */
class CORE_EXPORT QgsGeometryOptions : public QObject
{
    Q_OBJECT

  public:

    /**
     * Create a new QgsGeometryOptions object.
     */
    QgsGeometryOptions();

    /**
     * Automatically remove duplicate nodes on all geometries which are edited on this layer.
     *
     * \since QGIS 3.4
     */
    bool removeDuplicateNodes() const;

    /**
     * Automatically remove duplicate nodes on all geometries which are edited on this layer.
     *
     * \since QGIS 3.4
     */
    void setRemoveDuplicateNodes( bool value );

    /**
     * The precision in which geometries on this layer should be saved.
     * Geometries which are edited on this layer will be rounded to multiples of this value (snap to grid).
     * Set to 0.0 to disable.
     *
     * \since QGIS 3.4
     */
    double geometryPrecision() const;

    /**
     * The precision in which geometries on this layer should be saved.
     * Geometries which are edited on this layer will be rounded to multiples of this value (snap to grid).
     * Set to 0.0 to disable.
     *
     * \since QGIS 3.4
     */
    void setGeometryPrecision( double value );

    /**
     * Determines if at least one fix is enabled.
     *
     * \since QGIS 3.4
     */
    bool isActive() const;

    /**
     * Apply any fixes configured on this class to \a geometry.
     *
     * \since QGIS 3.4
     */
    void apply( QgsGeometry &geometry ) const;

    /**
     * A list of activated geometry checks.
     *
     * \since QGIS 3.4
     */
    QStringList geometryChecks() const;

    /**
     * A list of activated geometry checks.
     *
     * \since QGIS 3.4
     */
    void setGeometryChecks( const QStringList &geometryChecks );

    /**
     * Access the configuration for the check \a checkId.
     *
     * \since QGIS 3.4
     */
    QVariantMap checkConfiguration( const QString &checkId ) const;

    /**
     * Set the configuration for the check \a checkId.
     *
     * \since QGIS 3.4
     */
    void setCheckConfiguration( const QString &checkId, const QVariantMap &checkConfiguration );

    /**
     * Returns the expression which will be used to sort features when using the split features map tool.
     *
     * \see setSplitFeaturesOrderByExpression()
     * \see splitFeaturesSortOrder()
     * \see setSplitFeaturesSortOrder()
     *
     * \since QGIS 3.42
     */
    QString splitFeaturesOrderByExpression() const;

    /**
     * Sets the expression which will be used to sort features when using the split features map tool.
     *
     * \see splitFeaturesOrderByExpression()
     * \see splitFeaturesSortOrder()
     * \see setSplitFeaturesSortOrder()
     *
     * \since QGIS 3.42
     */
    void setSplitFeaturesOrderByExpression( const QString &expression );

    /**
     * Returns the order split features will be sorted by the expression
     *
     * \see splitFeaturesOrderByExpression()
     * \see setSplitFeaturesOrderByExpression()
     * \see setSplitFeaturesSortOrder()
     *
     * \since QGIS 3.42
     */
    Qt::SortOrder splitFeaturesSortOrder() const;

    /**
     * Sets the order split features will be sorted by the expression.
     *
     * \see splitFeaturesOrderByExpression()
     * \see setSplitFeaturesOrderByExpression()
     * \see splitFeaturesSortOrder()
     *
     * \since QGIS 3.42
     */
    void setSplitFeaturesSortOrder( Qt::SortOrder sortOrder );

    /**
     * Write the geometry options to the \a node.
     *
     * \since QGIS 3.4
     */
    void writeXml( QDomNode &node ) const;

    /**
     * Read the geometry options from \a node.
     *
     * \since QGIS 3.4
     */
    void readXml( const QDomNode &node );

#ifndef SIP_RUN
    //! Settings entry search path for templates
    static const QgsSettingsEntryString *settingsGeometryValidationDefaultChecks;
#endif

  signals:

    /**
     * Access the configuration for the check \a checkId.
     *
     * \since QGIS 3.4
     */
    void checkConfigurationChanged();

    /**
     * A list of activated geometry checks.
     *
     * \since QGIS 3.4
     */
    void geometryChecksChanged();

    /**
     * Automatically remove duplicate nodes on all geometries which are edited on this layer.
     *
     * \since QGIS 3.4
     */
    void removeDuplicateNodesChanged();

    /**
     * The precision in which geometries on this layer should be saved.
     * Geometries which are edited on this layer will be rounded to multiples of this value (snap to grid).
     * Set to 0.0 to disable.
     *
     * \since QGIS 3.4
     */
    void geometryPrecisionChanged();

    /**
     * The order in which new features will be created in when using the split features map tool.
     * The order is controlled by an expression and can be set to be either ascending or descending.
     *
     * \since QGIS 3.42
     */
    void splitFeaturesSortingChanged();

  private:

    /**
     * Automatically remove duplicate nodes on all geometries which are edited on this layer.
     *
     * \since QGIS 3.4
     */
    bool mRemoveDuplicateNodes = false;

    /**
     * The precision in which geometries on this layer should be saved.
     * Geometries which are edited on this layer will be rounded to multiples of this value (snap to grid).
     * Set to 0.0 to disable.
     *
     * \since QGIS 3.4
     */
    double mGeometryPrecision = 0.0;

    QStringList mGeometryChecks;
    QVariantMap mCheckConfiguration;

    QString mSplitFeaturesSortExpression;
    Qt::SortOrder mSplitFeaturesSortOrder = Qt::SortOrder::DescendingOrder;
};

#endif // QGSGEOMETRYOPTIONS_H
