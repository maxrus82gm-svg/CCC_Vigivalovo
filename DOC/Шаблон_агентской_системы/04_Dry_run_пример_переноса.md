# Dry-run пример переноса

Этот документ нужен для безопасной проверки шаблона без переноса в реальный проект.

## Условный паспорт

```text
PROJECT_NAME: Example_Project
PROJECT_ROOT: D:\Projects\Example_Project
OBSIDIAN_VAULT: D:\Projects\Example_Project\Vault
DOC_FOLDER: D:\Projects\Example_Project\Vault\doc
REPOSITORY_URL: https://github.com/example/example-project.git
REPOSITORY_TYPE: GitHub
MAIN_TASK_FILE: D:\Projects\Example_Project\Vault\doc\Задача_агенту.md
START_FILE: D:\Projects\Example_Project\Vault\doc\Старт.md
RULES_FOLDER: D:\Projects\Example_Project\Vault\doc
PROJECT_TYPE: docs only
BUILD_SYSTEM: НЕ УКАЗАНО
CODE_FOLDERS: НЕ УКАЗАНО
ASSET_FOLDERS: НЕ УКАЗАНО
CONFIG_FOLDERS: НЕ УКАЗАНО
FORBIDDEN_FOLDERS: .git; .obsidian
AGENT_CONFIG_PATHS: НЕ УКАЗАНО
SUBAGENT_PROFILES: НЕ УКАЗАНО
CURRENT_BASE_COMMIT: НЕ УКАЗАНО
USER_GIT_POLICY: Git не использовать без прямой команды пользователя.
```

## Что проверить

1. Подставить значения из условного паспорта в один выбранный шаблон, например `Шаблоны_документов\Старт.md`.
2. Проверить, что документ читается как рабочий стартовый файл.
3. Проверить, что не осталось чужих путей.
4. Проверить, что неизвестные значения записаны как `НЕ УКАЗАНО`.
5. Не создавать реальный проект и не менять Git.

## Результат dry-run

Dry-run успешен, если агент может объяснить:

- какие placeholders были заменены;
- какие значения остались `НЕ УКАЗАНО`;
- какие документы нужно создать в реальном проекте;
- какие действия требуют уточнения пользователя.
