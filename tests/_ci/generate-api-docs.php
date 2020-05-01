<?php

declare(strict_types=1);

$baseDir   = dirname(dirname(__DIR__));
$sourceDir = implode(DIRECTORY_SEPARATOR, [$baseDir, 'phalcon', '']);
$outputDir = implode(DIRECTORY_SEPARATOR, [$baseDir, 'nikos', 'api', '']);

if (!is_dir($outputDir)) {
    mkdir($outputDir, 0777, true);
}

$iterator = new RecursiveIteratorIterator(
    new RecursiveDirectoryIterator(
        $sourceDir,
        FilesystemIterator::SKIP_DOTS
    ),
    RecursiveIteratorIterator::CHILD_FIRST
);

$iteratorDocs = [];
foreach ($iterator as $file) {
    if (true === $file->isFile()) {
        $iteratorDocs[] = str_replace($sourceDir, '', $file->getPathName());
    }
}

asort($iteratorDocs);

$documents = [];
foreach ($iteratorDocs as $fileName) {
    $split    = explode(DIRECTORY_SEPARATOR, $fileName);
    $title    = str_replace('Phalcon\\', '', $fileName);
    $key      = str_replace('.zep', '', $split[0]);

    $documents[$key]['title']           = 'Phalcon\\' . $key;
    $documents[$key]['docs'][implode('/', $split)] = $fileName;

    if (strpos($documents[$key]['title'], 'Url') > 0) {
        $documents[$key]['title'] = 'Phalcon\Url';
    }

    ksort($documents[$key]['docs']);
}

ksort($documents);

foreach ($documents as $document) {
    echo 'Processing: ' . $document['title'] . PHP_EOL;
    $output = "---
layout: default
language: 'en'
version: '4.0'
title: '{$document['title']}'
---
";
    foreach ($document['docs'] as $file) {
        $link   = str_replace(['.zep', DIRECTORY_SEPARATOR], ['', '\\'], $file);
        $href   = str_replace(['Phalcon\\', '\\'], ['', '-'], strtolower($link));
        $output .= "
* [Phalcon\\{$link}](#$href)";
    }

    $outputDoc = str_replace('\\', '_', $document['title']) . '.md';
    foreach ($document['docs'] as $file) {
        echo '    - ' . $file . PHP_EOL;
        $github = str_replace('\\', '/', $file);
        $href   = str_replace(['.zep', DIRECTORY_SEPARATOR], ['', '-'], strtolower($file));
        $file   = $sourceDir . $file;

        $data = processDocument($file);

        $classComment = $data['comment'] ?? '';
        $namespace    = $data['namespace'] ?? '';
        $uses         = $data['uses'] ?? '';
        $signature    = $data['signature'] ?? '';
        $extends      = $data['extends'] ?? '';
        $implements   = $data['implements'] ?? '';
        $constants    = $data['constants'] ?? [];
        $temp         = $data['properties'] ?? [];
        $properties   = $temp['properties'] ?? [];
        $shortcuts    = $temp['shortcuts'] ?? [];
        $methods      = $data['methods'] ?? [];
        $methods      = array_merge($shortcuts, $methods);
        $methods      = orderMethods($methods);

        $output .= "

<h1 id=\"{$href}\">{$signature}</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/blob/v{{ page.version }}.0/phalcon/{$github})
";

        if (!empty($namespace)) {
            $output .= "
| Namespace  | {$namespace} |";
        }

        if (!empty($uses)) {
            $uses   = implode(', ', $uses);
            $output .= "
| Uses       | {$uses} |";
        }

        if (!empty($extends)) {
            $output .= "
| Extends    | {$extends} |";
        }

        if (!empty($implements)) {
            $implements = implode(', ', $implements);
            $output     .= "
| Implements | {$implements} |";
        }

        $output .= "

{$classComment}
";

        if (count($constants) > 0) {
            $constants = implode(PHP_EOL, $constants);
            $output    .= "
## Constants
```php
{$constants}
```
";
        }

        if (count($properties) > 0) {
            $properties = implode(PHP_EOL, $properties);
            $output     .= "
## Properties
```php
{$properties}
```
";
        }

        if (count($methods) > 0) {
            $elements = [];
            foreach ($methods as $method) {
                // Ignore method params lines as they are already in signature
                $methodComment = preg_replace('/\@(param|return)(.+)\n?/s', '', $method['comment']);
                $methodComment = trim($methodComment, "\t\n");
                $methodComment = preg_replace('/^\/\/$/', '', $methodComment);

                $elements[] = $methodComment . PHP_EOL
                    . '```php' . PHP_EOL
                    . $method['signature'] . PHP_EOL
                    . '```' . PHP_EOL;
            }
            $signature = implode(PHP_EOL, $elements);
            $output    .= "
## Methods

{$signature}
";
        }
    }

    $outputDoc = strtolower(str_replace('.zep', '', $outputDoc));

    file_put_contents(
        $outputDir . $outputDoc,
        $output
    );
}

// API Json
$api = [];
foreach ($documents as $document) {
    $api[] = [
        'title' => $document['title'],
        'docs'  => array_map(
            function ($value) {
                return str_replace(['.zep', DIRECTORY_SEPARATOR], ['', '\\'], $value);
            },
            array_values($document['docs'])
        ),
    ];
}

file_put_contents(
    $outputDir . 'api.json',
    json_encode($api, JSON_PRETTY_PRINT)
);




/**
 * Read the file and parse it
 */
function processDocument(string $file): array
{
    $return   = [];
    $contents = file_get_contents($file);
    $parse    = zephir_parse_file($contents, '(eval code)');

    foreach ($parse as $item) {
        $type = $item['type'] ?? '';

        if ('namespace' === $type) {
            $return['namespace'] = $item['name'];

            continue;
        }

        if ('comment' === $type) {
            $return['comment'] = getDocblockMethod($item['value']);

            continue;
        }

        if ('use' === $type) {
            $uses    = $return['uses'] ?? [];
            $aliases = $item['aliases'];
            foreach ($aliases as $alias) {
                $uses[] = $alias['name'];
            }

            $return['uses'] = $uses;
        }

        if ('class' === $type || 'interface' === $type) {
            $signature = '';
            if (1 === ($item['final'] ?? 0)) {
                $signature .= ' Final';
            }
            if (1 === ($item['abstract'] ?? 0)) {
                $signature .= ' Abstract';
            }

            $signature           .= ('class' === $type) ? ' Class ' : ' Interface ';
            $signature           .= $return['namespace'] . '\\' . $item['name'];
            $return['signature'] = ltrim($signature);
            //$return['signature'] = ltrim(str_replace('Phalcon\\', '', $signature));

            $return['extends'] = $item['extends'] ?? '';
            if (true === is_array($return['extends'])) {
                $return['extends'] = $return['extends'][0]['value'];
            }

            $implements = $item['implements'] ?? [];
            if (count($implements) > 0) {
                foreach ($implements as $implement) {
                    $return['implements'][] = $implement['value'];
                }
            }

            $definition           = $item['definition'] ?? [];
            $return['constants']  = parseConstants($definition);
            $return['properties'] = parseProperties($definition);
            $return['methods']    = parseMethods($definition);
        }
    }

    return $return;
}

function parseConstants(array $item): array
{
    $constants = $item['constants'] ?? [];
    $return    = [];
    foreach ($constants as $constant) {
        if ('const' === $constant['type']) {
            $signature = 'const ' . $constant['name'];
            if (isset($constant['default']['value'])) {
                $signature .= ' = ' . $constant['default']['value'];
            }

            $return[$constant['name']] = $signature . ';';
        }
    }

    ksort($return);

    return $return;
}

function parseMethods(array $item): array
{
    $methods = $item['methods'] ?? [];
    $return  = [];

    foreach ($methods as $method) {
        $line = $method['docblock'] ?? '';
        $line = getDocblockMethod($line);

        $visibility = $method['visibility'] ?? [];
        $signature  = implode(' ', $visibility);
        $signature .= ' function ' . $method['name'] . '(';

        $params  = $method['parameters'] ?? [];
        $counter = 1;
        $count   = count($params);
        foreach ($params as $param) {
            if ('parameter' === $param['type']) {
                $cast = $param['cast'] ?? [];
                if (count($cast) > 0) {
                    $type = transformType($cast['type'], $cast['value']);
                } else {
                    $type = transformType($param['data-type']);
                }
                $signature .= ' ' . $type . ' $' . $param['name'];


                // Default value
                $retVal = $param['default']['type'] ?? '';
                $retVal = transformType($retVal);
                if (!empty($retVal)) {
                    $signature .= ' = ' . $retVal;
                }

                if ($counter < $count) {
                    $signature .= ',';
                }

                $counter++;
            }
        }

        $signature .= ($count > 0 ? ' ' : '') . ')';

        // Return
        $retType = $method['return-type'] ?? [];
        if (1 === ($retType['void'] ?? 0)) {
            $signature .= ': void';
        } else {
            $list = $retType['list'] ?? [];
            if (count($list) > 0) {
                $retTypes = [];
                foreach ($list as $li) {
                    $cast = $li['cast'] ?? [];
                    if (count($cast) > 0) {
                        $rt = transformType($cast['type'], $cast['value']);
                        if (1 === $li['collection']) {
                            $rt .= '[]';
                        }

                        $retTypes[] = $rt;
                    } else {
                        $retTypes[] = transformType($li['data-type']);
                    }
                }

                $signature .= ': ' . implode(' | ', $retTypes);
            }
        }

        $return[$method['name']] = [
            'comment'   => $line,
            'signature' => ltrim($signature) . ';',
        ];
    }

    return $return;
}

function parseProperties(array $item): array
{
    $properties = $item['properties'] ?? [];
    $return     = [];
    $sigReturn  = [];

    foreach ($properties as $property) {
        $line = $property['docblock'] ?? '';
        $line = getDocblock($line);

        $signature = '';

        $visibility = $property['visibility'] ?? [];
        foreach ($visibility as $vis) {
            $signature .= ' ' . $vis;
        }

        $signature .= ' ' . $property['name'];

        if (isset($property['default']['value'])) {
            $signature .= ' = ' . $property['default']['value'];
        }

        $retVal = '';
        $temp   = explode(PHP_EOL, $line);
        foreach ($temp as $li) {
            if (strpos($li, '@var') > 0) {
                $retVal = str_replace(' * @var ', '', $li);

                break;
            }
        }

        $shortcuts = $property['shortcuts'] ?? [];
        foreach ($shortcuts as $shortcut) {
            $stub = $shortcut['name'];
            if ('get' === $stub) {
                $name             = 'get' . ucfirst($property['name']);
                $sigReturn[$name] = [
                    'comment'   => '',
                    'signature' => 'public function ' . $name .
                        '()' . (!empty($retVal) ? ': ' . $retVal : ''),
                ];
            } elseif ('set' === $stub) {
                $name             = 'set' . ucfirst($property['name']);
                $sigReturn[$name] = [
                    'comment'   => '',
                    'signature' => 'public function ' . $name .
                        '( ' . (!empty($retVal) ? $retVal . ' ' : '') .
                        '$' . $property['name'] .
                        ' )',
                ];
            } elseif ('__toString' === $stub) {
                $sigReturn['__toString'] = [
                    'comment'   => '',
                    'signature' => 'public function __toString(): string',
                ];
            }
        }

        $return[$property['name']] = $line . PHP_EOL .
            ltrim($signature) . ';' . PHP_EOL;
    }

    return [
        'properties' => $return,
        'shortcuts'  => $sigReturn,
    ];
}

function getDocblockMethod(string $source): string
{
    $doc = getDocblock($source);

    return str_replace(
        [
            '/**' . PHP_EOL,
            '/**',
            ' */' . PHP_EOL,
            ' */',
            ' * ',
            ' *',
        ],
        [
            '',
            '',
            '',
            '',
            '',
            '',
        ],
        $doc
    );
}

function getDocblock(string $source): string
{
    $linesArray = [];
    $lines      = explode("\n", trim($source));

    foreach ($lines as $line) {
        $linesArray[] = str_replace(
            [
                '    /*',
                '     *',
            ],
            [
                '/*',
                ' *',
            ],
            $line
        );
    }

    $doc = implode(PHP_EOL, $linesArray);

    return '/' . $doc . '/';
}

function orderMethods(array $methods): array
{
    $public    = [];
    $reserved  = [];
    $protected = [];

    foreach ($methods as $name => $method) {
        if (substr($name, 0, 2) === '__') {
            $reserved[$name] = $method;

            continue;
        }

        if (strpos($method['signature'], 'public function') !== false ||
            strpos($method['signature'], 'public static function') !== false) {
            $public[$name] = $method;

            continue;
        }

        if (strpos($method['signature'], 'protected function') !== false ||
            strpos($method['signature'], 'protected static function') !== false) {
            $protected[$name] = $method;

            continue;
        }
    }

    ksort($reserved);
    ksort($public);
    ksort($protected);

    return array_merge($reserved, $public, $protected);
}

function transformType(string $type, string $value = ''): string
{
    switch ($type) {
        case 'variable':
            if (empty($value)) {
                return 'mixed';
            } else {
                return $value;
            }
        case 'empty-array':
            return '[]';
        default:
            return $type;
    }
}
