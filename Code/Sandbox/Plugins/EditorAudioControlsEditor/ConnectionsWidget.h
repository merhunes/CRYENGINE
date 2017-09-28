// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

#pragma once

#include <QWidget>

class QFrame;
class QPropertyTree;
class QDeepFilterProxyModel;

namespace ACE
{
class CAudioControl;
class CConnectionModel;
class CAudioTreeView;

class CConnectionsWidget final : public QWidget
{
	Q_OBJECT

public:

	CConnectionsWidget(QWidget* pParent = nullptr);
	virtual ~CConnectionsWidget() override;

	void SetControl(CAudioControl* pControl);
	void Reload();
	void BackupTreeViewStates();
	void RestoreTreeViewStates();

private slots:

	void OnContextMenu(QPoint const& pos);

private:

	// QObject
	bool eventFilter(QObject* pObject, QEvent* pEvent) override;
	// ~QObject

	void RemoveSelectedConnection();
	void RefreshConnectionProperties();

	CAudioControl*         m_pControl;
	QFrame*                m_pConnectionPropertiesFrame;
	QPropertyTree*         m_pConnectionProperties;
	QDeepFilterProxyModel* m_pFilterProxyModel;
	CConnectionModel*      m_pConnectionModel;
	CAudioTreeView*        m_pTreeView;
};
} // namespace ACE