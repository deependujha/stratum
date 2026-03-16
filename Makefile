.phony: test setup

test:
	@echo "Running Stratum tests..."
	@rm -rf build && mkdir -p build
	@cd build && cmake .. -DSTRATUM_BUILD_TESTS=ON
	@cd build && ctest --output-on-failure

setup:
	@echo "--- Setting up Stratum project... ---"
	@git submodule update --init --recursive
	@echo "--- Stratum setup completed successfully. ---"
