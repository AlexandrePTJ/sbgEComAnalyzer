// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: 2025 SBG Systems and Contributors

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

using namespace Qt::StringLiterals;

int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);

	QQmlApplicationEngine engine;
	engine.load(QUrl(QStringLiteral("qrc:/qt/qml/sbg/qml/main.qml")));

	if (engine.rootObjects().isEmpty())
		return -1;

	return app.exec();
}
