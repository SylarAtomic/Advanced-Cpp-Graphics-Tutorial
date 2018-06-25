#pragma once

namespace Bengine {
	class FpsLimiter {
	public:
		FpsLimiter();
		void init(float maxFPS);

		void setMaxFPS(float maxFPS);

		void begin();

		// end will return the current FPS
		float end();
	private:
		void calcaulteFPS();

		float _fps;
		float _maxFPS;
		float _frameTime;
		unsigned int _startTicks;

	};
}