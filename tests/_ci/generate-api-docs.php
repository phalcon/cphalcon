<?php
declare(strict_types=1);

$baseDir = dirname(dirname(dirname(__FILE__)));
$sourceDir = $baseDir . '/phalcon/';
$outputDir = $baseDir . '/nikos/api/';

if (!is_dir($outputDir)) {
    mkdir($outputDir, 0777, true);
}

$documents = [
    [
        'title'  => 'Phalcon\Acl',
        'output' => 'Phalcon_Acl.md',
        'docs'   => [
            'Acl'                => 'Acl.zep',
            'Adapter_Memory'     => 'Acl/Adapter/Memory.zep',
            'Adapter'            => 'Acl/Adapter.zep',
            'AdapterInterface'   => 'Acl/AdapterInterface.zep',
            'Component'          => 'Acl/Component.zep',
            'ComponentAware'     => 'Acl/ComponentAware.zep',
            'ComponentInterface' => 'Acl/ComponentInterface.zep',
            'Exception'          => 'Acl/Exception.zep',
            'Role'               => 'Acl/Role.zep',
            'RoleAware'          => 'Acl/RoleAware.zep',
            'RoleInterface'      => 'Acl/RoleInterface.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Annotations',
        'output' => 'Phalcon_Annotations.md',
        'docs'   => [
            'Adapter_AbstractAdapter'  => 'Annotations/Adapter/AbstractAdapter.zep',
            'Adapter_AdapterInterface' => 'Annotations/Adapter/AdapterInterface.zep',
            'Adapter_Apcu'             => 'Annotations/Adapter/Apcu.zep',
            'Adapter_Memory'           => 'Annotations/Adapter/Memory.zep',
            'Adapter_Stream'           => 'Annotations/Adapter/Stream.zep',
            'Annotation'               => 'Annotations/Annotation.zep',
            'AnnotationsFactory'       => 'Annotations/AnnotationsFactory.zep',
            'Collection'               => 'Annotations/Collection.zep',
            'Exception'                => 'Annotations/Exception.zep',
            'Reader'                   => 'Annotations/Reader.zep',
            'ReaderInterface'          => 'Annotations/ReaderInterface.zep',
            'Reflection'               => 'Annotations/Reflection.zep',
        ],
    ],
];

foreach ($documents as $document) {
    echo 'Processing: ' . $document['title'] . PHP_EOL;
    $output = "---
layout: default
language: 'en'
version: '4.0'
title: '{$document['title']}'
---
";
    foreach ($document['docs'] as $href => $file) {
        $link = str_replace(['.zep', '/'], ['', '\\'], $file);
        $output .= "
* [Phalcon\\{$link}](#$href)";
    }

    $outputDoc    = str_replace('.md', '', $document['output']);
    foreach ($document['docs'] as $href => $file) {
        echo '    - ' . $file . PHP_EOL;
        $github = strtolower($file);
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

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/{$github})
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
                $elements[] = '```php' . PHP_EOL
                    . $method['signature'] . PHP_EOL
                    . '```' . PHP_EOL
                    . $method['comment'] . PHP_EOL;
            }
            $signature = implode(PHP_EOL, $elements);
            $output    .= "
## Methods
{$signature}
";
        }

    }

    file_put_contents(
        $outputDir . $document['output'],
        $output
    );
}

/**
 * Read the file and parse it
 *
 * @param string $file
 *
 * @return array
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
            };
            if (1 === ($item['abstract'] ?? 0)) {
                $signature .= ' Abstract';
            };

            $signature           .= ('class' === $type) ? ' Class ' : ' Interface ';
            $signature           .= $return['namespace'] . '\\' . $item['name'];
            $return['signature'] = ltrim($signature);

            $return['extends'] = $item['extends'] ?? '';

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

        $signature  = '';
        $visibility = $method['visibility'] ?? [];
        foreach ($visibility as $vis) {
            $signature .= ' ' . $vis;
        }

        $signature .= ' function ' . $method['name'] . '(';

        $params  = $method['parameters'] ?? [];
        $counter = 1;
        $count   = count($params);
        foreach ($params as $param) {
            if ('parameter' === $param['type']) {
                $type = $param['data-type'];
                if ('variable' === $type) {
                    $type = 'mixed';
                }
                $signature .= ' ' . $type . ' $' . $param['name'];
                // Default value
                $retVal = $param['default']['type'] ?? '';
                $retVal = str_replace('empty-array', '[]', $retVal);
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
                        $rt = $cast['value'];
                        if (1 === $li['collection']) {
                            $rt .= '[]';
                        }

                        $retTypes[] = $rt;
                    } else {
                        $retTypes[] = str_replace(
                            'empty-array',
                            '[]',
                            $li['data-type']
                        );
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
                $name = 'get' . ucfirst($property['name']);
                $sigReturn[$name] = [
                    'comment'   => '',
                    'signature' => 'public function ' . $name .
                        '()' . (!empty($retVal) ? ': ' . $retVal : ''),
                ];
            } elseif ('set' === $stub) {
                $name = 'set' . ucfirst($property['name']);
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

function orderMethods($methods): array
{
    if (is_array($methods)) {
        $public    = [];
        $reserved  = [];
        $protected = [];

        foreach ($methods as $name => $method) {
            if (substr($name, 0, 2) === '__') {
                $reserved[$name] = $method;
                continue;
            }

            if (strpos($method['signature'], 'public function') !== false) {
                $public[$name] = $method;
                continue;
            }

            if (strpos($method['signature'], 'protected function') !== false) {
                $protected[$name] = $method;
                continue;
            }
        }

        ksort($reserved);
        ksort($public);
        ksort($protected);

        return array_merge($reserved, $public, $protected);
    } else {
        return $methods;
    }
}
