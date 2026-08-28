/*
This file is part of 64Gram Desktop,
the unofficial app based on Telegram Desktop.
For license and copyright information please follow this link:
https://github.com/TDesktop-x64/tdesktop/blob/dev/LEGAL
*/
#pragma once

#include "rpl/producer.h"

#include <QtCore/QTimer>

namespace EnhancedSettings {

	inline constexpr auto kRichMessagePreviewBlocksLimitMin = 5;
	inline constexpr auto kRichMessagePreviewBlocksLimitMax = 50;
	inline constexpr auto kStickerHeightMin = 64;
	inline constexpr auto kStickerHeightMax = 256;

	[[nodiscard]] int RichMessagePreviewBlocksLimit();
	void SetRichMessagePreviewBlocksLimit(int limit);
	[[nodiscard]] int StickerHeight();
	void SetStickerHeight(int height);
	[[nodiscard]] bool ExactSearchIntersection();
	void SetExactSearchIntersection(bool enabled);
	[[nodiscard]] rpl::producer<bool> ExactSearchIntersectionValue();

	class Manager : public QObject {
	Q_OBJECT

	public:
		Manager();

		void fill();

		void write(bool force = false);

		void addIdToBlocklist(int64 userId);

		void removeIdFromBlocklist(int64 userId);

		void readBlocklist();

	public Q_SLOTS:

		void writeTimeout();

	private:
		void writeDefaultFile();

		void writeCurrentSettings();

		bool readCustomFile();

		void writing();

		QTimer _jsonWriteTimer;

	};

	void Start();

	void Write();

	void Finish();

} // namespace EnhancedSettings
