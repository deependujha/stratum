.phony: test setup pre-commit submodule ntidy_commit

test:
	@echo "Running Stratum tests..."
	@rm -rf build && mkdir -p build
	@cd build && cmake .. -DSTRATUM_BUILD_TESTS=ON
	@cd build && ctest --output-on-failure

setup: submodule pre-commit
	@echo "--- ✅ Stratum setup completed successfully. ---"

pre-commit:
	@echo "Setting up pre-commit hooks..."
	@chmod +x scripts/lint-cpp-codes.sh
	@mkdir -p .git/hooks
	@ln -sf ../../scripts/lint-cpp-codes.sh .git/hooks/pre-commit
	@echo "Pre-commit hooks set up successfully."

submodule:
	@echo "Initializing and updating git submodules..."
	@git submodule update --init --recursive
	@echo "Git submodules initialized and updated successfully."

# not tidy (ignore clang-tidy error)
ntidy_commit:
	git add .
	IGNORE_CLANG_TIDY_ERROR=1 git commit

