#!/usr/bin/env php
<?php

/**
 * Sister script to generate-api-docs.php producing the redesigned API
 * documentation layout (hierarchy tree, method summary rows, visibility
 * chips, multi-line signatures).
 *
 * Two passes:
 *   1. Parse every .zep file with zephir_parse_file() and build a global
 *      class registry (FQCN -> metadata) so inheritance trees and
 *      cross-page links can be resolved.
 *   2. Emit one markdown file per top-level namespace segment.
 *
 * Usage:
 *   php bin/generate-api-docs-v2.php [pageFilter] [outputDir]
 *
 *   pageFilter  Only emit pages whose key matches (e.g. "Encryption").
 *               The registry is always built from all files.
 *   outputDir   Defaults to nikos/api-v2/
 */

declare(strict_types=1);

if (!function_exists('zephir_parse_file')) {
    fwrite(STDERR, 'The zephir parser extension is not loaded.' . PHP_EOL);
    exit(1);
}

$baseDir   = dirname(__DIR__);
$sourceDir = $baseDir . DIRECTORY_SEPARATOR . 'phalcon' . DIRECTORY_SEPARATOR;
$filter    = $argv[1] ?? '';
$outputDir = rtrim($argv[2] ?? $baseDir . '/nikos/api', '/') . '/';

if (!is_dir($outputDir)) {
    mkdir($outputDir, 0777, true);
}

/*
 * Pass 1 - registry
 */
$registry = [];
foreach (collectZepFiles($sourceDir) as $relPath) {
    $ast = zephir_parse_file(
        file_get_contents($sourceDir . $relPath),
        $relPath
    );

    $class = extractClass($ast, $relPath);
    if (null !== $class) {
        $registry[$class['fqcn']] = $class;
    }
}

resolveRegistry($registry);

/*
 * Pass 2 - emit pages
 */
$pages = [];
foreach ($registry as $fqcn => $class) {
    $pages[$class['page']][] = $fqcn;
}

ksort($pages);

foreach ($pages as $page => $fqcns) {
    if ('' !== $filter && false === stripos($page, strtolower($filter))) {
        continue;
    }

    echo 'Processing: ' . $page . PHP_EOL;

    sort($fqcns);

    $output = <<<EOT
---
hide:
    - navigation
---

!!! info "NOTE"

    All classes are prefixed with `Phalcon`

EOT;

    foreach ($fqcns as $fqcn) {
        $output .= emitClassDoc($registry[$fqcn], $registry);
    }

    file_put_contents($outputDir . $page . '.md', $output);
}

echo 'Done. Output: ' . $outputDir . PHP_EOL;


/**
 * Walks the extends chain upwards; returns ancestors from root to parent.
 *
 * @return array<int, array{display: string, fqcn: ?string}>
 */
function ancestorsOf(array $class, array $registry): array
{
    $chain = [];
    $seen  = [$class['fqcn'] => true];
    $fqcn  = $class['extendsFqcn'][0] ?? null;
    $name  = $class['extends'][0] ?? null;

    while (null !== $name) {
        $entry = [
            'display' => $fqcn ?? $name,
            'fqcn'    => (null !== $fqcn && isset($registry[$fqcn])) ? $fqcn : null,
        ];
        array_unshift($chain, $entry);

        if (null === $entry['fqcn'] || isset($seen[$entry['fqcn']])) {
            break;
        }

        $seen[$entry['fqcn']] = true;

        $parent = $registry[$entry['fqcn']];
        $fqcn   = $parent['extendsFqcn'][0] ?? null;
        $name   = $parent['extends'][0] ?? null;
    }

    return $chain;
}

/**
 * Strips the comment decoration, returning clean text lines.
 */
function cleanDocblock(?string $raw): string
{
    if (null === $raw || '' === $raw) {
        return '';
    }

    $lines  = explode("\n", $raw);
    $output = [];
    foreach ($lines as $line) {
        $line = trim($line);
        if ('**' === $line || '*' === $line || '*/' === $line) {
            $output[] = '';
            continue;
        }
        if (0 === strpos($line, '* ')) {
            $output[] = substr($line, 2);
            continue;
        }
        if ('*' === substr($line, 0, 1)) {
            $output[] = ltrim(substr($line, 1));
            continue;
        }
        $output[] = $line;
    }

    return trim(implode("\n", $output), "\n");
}

/**
 * @return array<int, string> relative paths of all .zep files
 */
function collectZepFiles(string $sourceDir): array
{
    $iterator = new RecursiveIteratorIterator(
        new RecursiveDirectoryIterator(
            $sourceDir,
            FilesystemIterator::SKIP_DOTS
        ),
        RecursiveIteratorIterator::CHILD_FIRST
    );

    $files = [];
    foreach ($iterator as $file) {
        if ($file->isFile() && 'zep' === $file->getExtension()) {
            $files[] = str_replace($sourceDir, '', $file->getPathname());
        }
    }

    sort($files);

    return $files;
}

/**
 * Removes the tag block from a cleaned docblock, keeping prose,
 * examples and informational tags such as @todo.
 */
function descriptionOf(string $cleanDocblock): string
{
    $lines    = explode("\n", $cleanDocblock);
    $output   = [];
    $skipping = false;
    foreach ($lines as $line) {
        $trimmed = trim($line);

        /**
         * Multi-line tags (e.g. "@phpstan-type TOptions array{") are
         * swallowed up to the next blank line.
         */
        if ($skipping) {
            if ('' === $trimmed) {
                $skipping = false;
            }
            continue;
        }

        if (preg_match('/^@(param|return|throws|var|deprecated|phpstan-\S+|psalm-\S+)\b/', $trimmed)) {
            $skipping = true;
            continue;
        }

        $output[] = $line;
    }

    $text = implode("\n", $output);
    $text = preg_replace("/\n{3,}/", "\n\n", $text);

    return trim($text, "\n");
}

function emitClassDoc(array $class, array $registry): string
{
    $badge = 'Class';
    $css   = 'class';
    if ($class['interface']) {
        $badge = 'Interface';
        $css   = 'interface';
    } elseif ($class['abstract']) {
        $badge = 'Abstract';
        $css   = 'abstract';
    } elseif ($class['final']) {
        $badge = 'Final';
        $css   = 'final';
    }

    $github = str_replace('\\', '/', $class['relPath']);

    $output = "\n\n## {$class['title']}\n\n"
        . "<span class=\"badge badge--{$css}\">{$badge}</span>\n"
        . "[:material-github: Source on GitHub]"
        . "(https://github.com/phalcon/cphalcon/blob/5.0.x/phalcon/{$github})"
        . "{ .src-btn }\n";

    $description = descriptionOf($class['comment']);
    if ('' !== $description) {
        $output .= "\n" . $description . "\n";
    }

    $output .= emitTree($class, $registry);
    $output .= emitUses($class);
    $output .= emitSummary($class);
    $output .= emitConstants($class);
    $output .= emitProperties($class);
    $output .= emitMethodDetails($class);

    return $output;
}

function emitConstants(array $class): string
{
    if ([] === $class['constants']) {
        return '';
    }

    $output = "\n### Constants\n\n<div class=\"api-list\">\n";
    foreach ($class['constants'] as $constant) {
        $output .= "<div class=\"api-item\">\n"
            . '<code class="ret">' . e($constant['varType']) . "</code>\n"
            . '<code class="sig"><span class="sc">' . e($constant['name'])
            . '</span>' . htmlDefault($constant['default']) . "</code>\n";

        if ('' !== $constant['desc']) {
            $output .= '<span class="desc">'
                . inlineCodeToHtml($constant['desc']) . "</span>\n";
        }

        $output .= "</div>\n";
    }

    return $output . "</div>\n";
}

function emitMethodDetails(array $class): string
{
    if ([] === $class['methods']) {
        return '';
    }

    $groups = orderMethodsV2($class['methods']);
    $output = "\n### Methods\n";

    foreach (['public', 'protected'] as $group) {
        if ([] === $groups[$group]) {
            continue;
        }

        $count  = count($groups[$group]);
        $label  = ucfirst($group);
        $output .= "\n<div class=\"api-group\">{$label} · {$count}</div>\n";

        foreach ($groups[$group] as $method) {
            $anchor    = methodAnchor($class, $method['name']);
            $signature = implode("\n", renderSignatureLines($method));

            $output .= "\n#### `{$method['name']}()` { #{$anchor} }\n\n"
                . "```php\n{$signature}\n```\n";

            if ('' !== $method['desc']) {
                $output .= "\n" . $method['desc'] . "\n";
            }
        }
    }

    return $output;
}

function emitProperties(array $class): string
{
    if ([] === $class['properties']) {
        return '';
    }

    $output = "\n### Properties\n\n<div class=\"api-list\">\n";
    foreach ($class['properties'] as $property) {
        $visibility = $property['visibility'];

        $output .= "<div class=\"api-item\">\n"
            . "<code class=\"vis vis-{$visibility}\">{$visibility}</code>\n"
            . '<code class="ret">' . e($property['varType']) . "</code>\n"
            . '<code class="sig"><span class="sv">$' . e($property['name'])
            . '</span>' . htmlDefault($property['default']) . "</code>\n";

        if ('' !== $property['desc']) {
            $output .= '<span class="desc">'
                . inlineCodeToHtml($property['desc']) . "</span>\n";
        }

        $output .= "</div>\n";
    }

    return $output . "</div>\n";
}

function emitSummary(array $class): string
{
    if ([] === $class['methods']) {
        return '';
    }

    $groups = orderMethodsV2($class['methods']);
    $output = "\n### Method Summary\n\n<div class=\"api-list\">\n";

    foreach (['public', 'protected'] as $group) {
        foreach ($groups[$group] as $method) {
            $anchor = methodAnchor($class, $method['name']);
            $sig    = renderInlineSignatureHtml($method);

            $output .= "<a class=\"api-item\" href=\"#{$anchor}\">\n"
                . "<code class=\"vis vis-{$group}\">{$group}</code>\n";

            $return = renderReturn($method);
            if (null !== $return) {
                $output .= '<code class="ret">' . e($return) . "</code>\n";
            }

            $output .= "<code class=\"sig\">{$sig}</code>\n";

            $line = summaryLine($method['desc']);
            if ('' !== $line) {
                $output .= '<span class="desc">'
                    . inlineCodeToHtml($line) . "</span>\n";
            }

            $output .= "</a>\n";
        }
    }

    return $output . "</div>\n";
}

function emitTree(array $class, array $registry): string
{
    $ancestors = ancestorsOf($class, $registry);
    $level     = 0;
    $lines     = [];

    foreach ($ancestors as $ancestor) {
        $lines[] = str_repeat(' ', $level * 4) . '- '
            . fqcnLink($ancestor['display'], $ancestor['fqcn'], $registry, $class['page']);
        $level++;
    }

    $current = str_repeat(' ', $level * 4) . "- **`{$class['fqcn']}`**";

    $annotations = [];
    if ($class['interface'] && count($class['extends']) > 1) {
        $links = [];
        foreach ($class['extends'] as $index => $name) {
            $fqcn    = $class['extendsFqcn'][$index] ?? null;
            $links[] = fqcnLink($fqcn ?? $name, $fqcn, $registry, $class['page']);
        }
        $annotations[] = 'extends ' . implode(', ', $links);
    }

    if ([] !== $class['implementsFqcn']) {
        $links = [];
        foreach ($class['implements'] as $index => $name) {
            $fqcn    = $class['implementsFqcn'][$index] ?? null;
            $links[] = fqcnLink($fqcn ?? $name, $fqcn, $registry, $class['page']);
        }
        $annotations[] = 'implements ' . implode(', ', $links);
    }

    if ([] !== $annotations) {
        $current .= ' — ' . implode('; ', $annotations);
    }

    $lines[] = $current;
    $level++;

    $children = $class['children'] ?? [];
    sort($children);
    foreach ($children as $child) {
        $lines[] = str_repeat(' ', $level * 4) . '- '
            . fqcnLink($child, $child, $registry, $class['page']);
    }

    return "\n<div class=\"api-tree\" markdown>\n\n"
        . implode("\n", $lines)
        . "\n\n</div>\n";
}

function emitUses(array $class): string
{
    if ([] === $class['uses']) {
        return '';
    }

    $uses = $class['uses'];
    sort($uses);

    $codes = array_map(
        static fn (string $use): string => "`{$use}`",
        $uses
    );

    return "\n__Uses__ " . implode(' · ', $codes) . "\n{ .api-uses }\n";
}

/**
 * Reduces a parsed file to the slim structure the generator needs.
 */
function extractClass(array $ast, string $relPath): ?array
{
    $namespace = '';
    $uses      = [];
    $usesMap   = [];
    $comment   = '';
    $node      = null;
    $interface = false;

    foreach ($ast as $item) {
        $type = $item['type'] ?? '';

        if ('namespace' === $type) {
            $namespace = $item['name'];
            $comment   = '';
        } elseif ('comment' === $type) {
            $comment = $item['value'] ?? '';
        } elseif ('use' === $type) {
            $comment = '';
            foreach ($item['aliases'] ?? [] as $alias) {
                $uses[] = $alias['name'];

                $short = $alias['alias']
                    ?? substr((string) strrchr('\\' . $alias['name'], '\\'), 1);

                $usesMap[$short] = $alias['name'];
            }
        } elseif ('class' === $type || 'interface' === $type) {
            $node      = $item;
            $interface = ('interface' === $type);
            break;
        }
    }

    if (null === $node) {
        return null;
    }

    $fqcn  = $namespace . '\\' . $node['name'];
    $title = preg_replace('/^Phalcon\\\\/', '', $fqcn);

    $extends = $node['extends'] ?? null;
    if (is_string($extends) && '' !== $extends) {
        $extends = [$extends];
    } elseif (is_array($extends)) {
        $extends = array_map(
            static fn (array $entry): string => $entry['value'],
            $extends
        );
    } else {
        $extends = [];
    }

    $implements = array_map(
        static fn (array $entry): string => $entry['value'],
        $node['implements'] ?? []
    );

    $definition = $node['definition'] ?? [];

    return [
        'fqcn'           => $fqcn,
        'title'          => $title,
        'page'           => pageKeyForRelPath($relPath),
        'anchor'         => slugify($title),
        'relPath'        => $relPath,
        'namespace'      => $namespace,
        'interface'      => $interface,
        'abstract'       => 1 === ($node['abstract'] ?? 0),
        'final'          => 1 === ($node['final'] ?? 0),
        'comment'        => cleanDocblock($comment),
        'uses'           => $uses,
        'usesMap'        => $usesMap,
        'extends'        => $extends,
        'extendsFqcn'    => [],
        'implements'     => $implements,
        'implementsFqcn' => [],
        'children'       => [],
        'constants'      => extractConstants($definition),
        'properties'     => extractProperties($definition),
        'methods'        => extractMethods($definition),
    ];
}

function extractConstants(array $definition): array
{
    $constants = [];
    foreach ($definition['constants'] ?? [] as $constant) {
        if ('const' !== ($constant['type'] ?? '')) {
            continue;
        }

        $clean = cleanDocblock($constant['docblock'] ?? '');

        $constants[$constant['name']] = [
            'name'    => $constant['name'],
            'default' => $constant['default'] ?? null,
            'varType' => varTypeFrom($clean, $constant['default'] ?? null),
            'desc'    => descriptionOf($clean),
        ];
    }

    ksort($constants);

    return array_values($constants);
}

function extractMethods(array $definition): array
{
    $methods = [];
    foreach ($definition['methods'] ?? [] as $method) {
        $visibility = $method['visibility'] ?? [];
        if (in_array('private', $visibility, true)) {
            continue;
        }

        $parameters = [];
        foreach ($method['parameters'] ?? [] as $parameter) {
            if ('parameter' !== ($parameter['type'] ?? '')) {
                continue;
            }

            $parameters[] = [
                'name'    => $parameter['name'],
                'type'    => typeOfParam($parameter),
                'default' => $parameter['default'] ?? null,
            ];
        }

        $methods[$method['name']] = [
            'name'       => $method['name'],
            'visibility' => $visibility,
            'parameters' => $parameters,
            'returnType' => $method['return-type'] ?? null,
            'desc'       => descriptionOf(
                cleanDocblock($method['docblock'] ?? '')
            ),
        ];
    }

    return $methods;
}

function extractProperties(array $definition): array
{
    $properties = [];
    foreach ($definition['properties'] ?? [] as $property) {
        $visibility = $property['visibility'] ?? [];
        if (in_array('private', $visibility, true)) {
            continue;
        }

        $clean = cleanDocblock($property['docblock'] ?? '');
        $vis   = in_array('public', $visibility, true) ? 'public' : 'protected';

        $properties[$property['name']] = [
            'name'       => $property['name'],
            'visibility' => $vis,
            'default'    => $property['default'] ?? null,
            'varType'    => varTypeFrom($clean, $property['default'] ?? null),
            'desc'       => descriptionOf($clean),
            'shortcuts'  => array_map(
                static fn (array $shortcut): string => $shortcut['name'],
                $property['shortcuts'] ?? []
            ),
        ];
    }

    ksort($properties);

    return array_values($properties);
}

function e(string $text): string
{
    return htmlspecialchars($text, ENT_QUOTES | ENT_SUBSTITUTE);
}

/**
 * Markdown link to a class if it is in the registry, plain code otherwise.
 */
function fqcnLink(string $display, ?string $fqcn, array $registry, string $currentPage): string
{
    if (null === $fqcn || !isset($registry[$fqcn])) {
        return "`{$display}`";
    }

    $target = $registry[$fqcn];
    $href   = '#' . $target['anchor'];
    if ($target['page'] !== $currentPage) {
        $href = $target['page'] . '.md' . $href;
    }

    return "[`{$display}`]({$href})";
}

/**
 * Default-value expression as a muted highlight span, or empty.
 */
function htmlDefault(?array $expr): string
{
    if (null === $expr) {
        return '';
    }

    return '<span class="sm"> = ' . e(renderDefaultExpr($expr)) . '</span>';
}

/**
 * @return array<int, string> one HTML-rendered string per parameter
 */
function htmlParams(array $parameters): array
{
    $rendered = [];
    foreach ($parameters as $parameter) {
        $rendered[] = '<span class="st">' . e($parameter['type']) . '</span>'
            . ' <span class="sv">$' . e($parameter['name']) . '</span>'
            . htmlDefault($parameter['default']);
    }

    return $rendered;
}

function indentLines(string $text, int $spaces): string
{
    $pad   = str_repeat(' ', $spaces);
    $lines = array_map(
        static fn (string $line): string => '' === $line ? '' : $pad . $line,
        explode("\n", $text)
    );

    return implode("\n", $lines);
}

/**
 * Escaped text with markdown backtick spans converted to <code>.
 */
function inlineCodeToHtml(string $text): string
{
    return preg_replace('/`([^`]+)`/', '<code>$1</code>', e($text));
}

function methodAnchor(array $class, string $methodName): string
{
    return $class['anchor'] . '-' . strtolower($methodName);
}

/**
 * Reserved (__*) methods first, then alphabetical; split by visibility.
 *
 * @return array{public: array, protected: array}
 */
function orderMethodsV2(array $methods): array
{
    $groups = ['public' => [], 'protected' => []];
    foreach ($methods as $method) {
        $key = in_array('protected', $method['visibility'], true)
            ? 'protected'
            : 'public';

        $groups[$key][$method['name']] = $method;
    }

    foreach ($groups as $key => $group) {
        uksort(
            $group,
            static function (string $a, string $b): int {
                $ra = (int) (0 !== strpos($a, '__'));
                $rb = (int) (0 !== strpos($b, '__'));

                return [$ra, $a] <=> [$rb, $b];
            }
        );

        $groups[$key] = array_values($group);
    }

    return $groups;
}

function pageKeyForRelPath(string $relPath): string
{
    $segments = explode(DIRECTORY_SEPARATOR, $relPath);
    $key      = str_replace('.zep', '', $segments[0]);

    return 'phalcon_' . strtolower($key);
}

/**
 * Renders a default-value expression from the AST.
 */
function renderDefaultExpr(?array $expr): string
{
    if (null === $expr) {
        return '';
    }

    switch ($expr['type'] ?? '') {
        case 'string':
            return '"' . $expr['value'] . '"';
        case 'char':
            return "'" . $expr['value'] . "'";
        case 'int':
        case 'uint':
        case 'long':
        case 'double':
            return (string) $expr['value'];
        case 'bool':
            return (string) $expr['value'];
        case 'null':
            return 'null';
        case 'empty-array':
            return '[]';
        case 'array':
            return '[...]';
        case 'static-constant-access':
            return ($expr['left']['value'] ?? 'self') . '::'
                . ($expr['right']['value'] ?? '');
        case 'constant':
            return (string) ($expr['value'] ?? '');
        case 'minus':
            return '-' . renderDefaultExpr($expr['left'] ?? null);
        default:
            return (string) ($expr['value'] ?? $expr['type'] ?? '');
    }
}

/**
 * Signature for the summary rows as HTML with highlight spans.
 * With 2+ parameters each one is wrapped in a .prm span which the CSS
 * renders as its own indented line; the markup itself stays on one
 * line so the markdown pipeline cannot disturb it.
 */
function renderInlineSignatureHtml(array $method): string
{
    $name   = '<span class="sf">' . e($method['name']) . '</span>';
    $params = htmlParams($method['parameters']);

    if (count($method['parameters']) < 2) {
        $inline = implode(', ', $params);
        $inline = '' !== $inline ? '( ' . $inline . ' )' : '()';

        return $name . $inline;
    }

    $lines = '';
    $last  = count($params) - 1;
    foreach ($params as $index => $param) {
        $comma = $index < $last ? ',' : '';
        $lines .= '<span class="prm">' . $param . $comma . '</span>';
    }

    return $name . '(' . $lines . ')';
}

/**
 * @return array<int, string> one rendered string per parameter
 */
function renderParams(array $parameters): array
{
    $rendered = [];
    foreach ($parameters as $parameter) {
        $param = $parameter['type'] . ' $' . $parameter['name'];
        if (null !== $parameter['default']) {
            $param .= ' = ' . renderDefaultExpr($parameter['default']);
        }

        $rendered[] = $param;
    }

    return $rendered;
}

function renderReturn(array $method): ?string
{
    $returnType = $method['returnType'];
    if (null === $returnType) {
        return null;
    }

    if (1 === ($returnType['void'] ?? 0)) {
        return 'void';
    }

    $types = [];
    foreach ($returnType['list'] ?? [] as $entry) {
        $cast = $entry['cast'] ?? [];
        if ([] !== $cast) {
            $type = $cast['value'];
            if (1 === ($entry['collection'] ?? 0)) {
                $type .= '[]';
            }
        } else {
            $type = $entry['data-type'] ?? 'mixed';
            if ('variable' === $type) {
                $type = 'mixed';
            }
        }

        $types[] = $type;
    }

    if ([] === $types) {
        return null;
    }

    return implode('|', $types);
}

/**
 * @return array<int, string> lines of the fenced signature block
 */
function renderSignatureLines(array $method): array
{
    $prefix = implode(' ', $method['visibility']) . ' function '
        . $method['name'];

    $return = renderReturn($method);
    $suffix = (null !== $return ? ': ' . $return : '') . ';';

    $params = renderParams($method['parameters']);
    if (count($params) < 2) {
        $inline = implode(', ', $params);
        $inline = '' !== $inline ? '( ' . $inline . ' )' : '()';

        return [$prefix . $inline . $suffix];
    }

    $lines = [$prefix . '('];
    foreach ($params as $index => $param) {
        $comma   = $index < count($params) - 1 ? ',' : '';
        $lines[] = '    ' . $param . $comma;
    }
    $lines[] = ')' . $suffix;

    return $lines;
}

/**
 * Resolves short names to FQCNs and builds the children index.
 */
function resolveRegistry(array &$registry): void
{
    foreach ($registry as $fqcn => $class) {
        foreach (['extends', 'implements'] as $relation) {
            $resolved = [];
            foreach ($class[$relation] as $name) {
                $resolved[] = resolveShort($name, $class, $registry);
            }
            $registry[$fqcn][$relation . 'Fqcn'] = $resolved;
        }
    }

    foreach ($registry as $fqcn => $class) {
        $parent = $class['extendsFqcn'][0] ?? null;
        if (null !== $parent && isset($registry[$parent])) {
            $registry[$parent]['children'][] = $fqcn;
        }
    }
}

/**
 * Short name -> FQCN using the use map, the namespace, then Phalcon root.
 */
function resolveShort(string $name, array $class, array $registry): ?string
{
    if ('\\' === substr($name, 0, 1)) {
        $absolute = ltrim($name, '\\');

        return isset($registry[$absolute]) ? $absolute : null;
    }

    $candidates = [
        $class['usesMap'][$name] ?? null,
        $class['namespace'] . '\\' . $name,
        'Phalcon\\' . $name,
    ];

    foreach ($candidates as $candidate) {
        if (null !== $candidate && isset($registry[$candidate])) {
            return $candidate;
        }
    }

    return null;
}

/**
 * Mirrors the mkdocs toc slugify: lowercase, strip non-word characters.
 */
function slugify(string $title): string
{
    return strtolower(preg_replace('/[^\w\s-]/', '', $title));
}

/**
 * First prose line of a description, used in the summary rows.
 */
function summaryLine(string $description): string
{
    foreach (explode("\n", $description) as $line) {
        $line = trim($line);
        if ('' === $line) {
            continue;
        }
        if (0 === strpos($line, '```')) {
            return '';
        }

        return $line;
    }

    return '';
}

function typeOfParam(array $parameter): string
{
    $cast = $parameter['cast'] ?? [];
    if ([] !== $cast) {
        return $cast['value'];
    }

    $type = $parameter['data-type'] ?? 'variable';

    return 'variable' === $type ? 'mixed' : $type;
}

/**
 * Type from the @var tag, falling back to the default value's type.
 */
function varTypeFrom(string $cleanDocblock, ?array $default): string
{
    if (preg_match('/^@var\s+(.+)$/m', $cleanDocblock, $matches)) {
        return trim($matches[1]);
    }

    $map = [
        'string'      => 'string',
        'char'        => 'string',
        'int'         => 'int',
        'uint'        => 'int',
        'long'        => 'int',
        'double'      => 'float',
        'bool'        => 'bool',
        'empty-array' => 'array',
        'array'       => 'array',
        'null'        => 'mixed',
    ];

    return $map[$default['type'] ?? ''] ?? 'mixed';
}
