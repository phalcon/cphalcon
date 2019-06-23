<?php
declare(strict_types=1);

$root = dirname(dirname(dirname(__FILE__))) . '/phalcon/';

$documents = [
    [
        'title'  => 'Phalcon\Acl',
        'output' => 'Phalcon_Acl.md',
        'docs'   => [
//            '#Acl'                => 'Acl.zep',
//            '#Adapter_Memory'     => 'Acl/Adapter/Memory.zep',
//            '#Adapter'            => 'Acl/Adapter.zep',
            '#AdapterInterface'   => 'Acl/AdapterInterface.zep',
//            '#Component'          => 'Acl/Component.zep',
//            '#ComponentAware'     => 'Acl/ComponentAware.zep',
//            '#ComponentInterface' => 'Acl/ComponentInterface.zep',
//            '#Exception'          => 'Acl/Exception.zep',
//            '#Role'               => 'Acl/Role.zep',
//            '#RoleAware'          => 'Acl/RoleAware.zep',
//            '#RoleInterface'      => 'Acl/RoleInterface.zep',
        ]
    ]
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
        echo '    - ' . $file . PHP_EOL;
        $github = strtolower($file);
        $file   = $root . $file;

        $data = processDocument($file);

        $classComment = $data['comment'] ?? '';
        $namespace    = $data['namespace'] ?? '';
        $uses         = $data['uses'] ?? '';
        $signature    = $data['signature'] ?? '';
        $extends      = $data['extends'] ?? '';
        $implements   = $data['implements'] ?? '';
        $constants    = $data['constants'] ?? [];
        // Check the shortcuts
        $properties   = $data['properties'] ?? [];
        $methods      = $data['methods'] ?? [];

        $output .= "
<a name='{$href}'></a>
# {$signature}

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/{$github})
";

        if (!empty($namespace)) {
            $output .= "
| Namespace  | {$namespace} |";
        }

        if (!empty($uses)) {
            $uses = implode(', ', $uses);
            $output .= "
| Uses       | {$uses} |";
        }

        if (!empty($extends)) {
            $output .= "
| Extends    | {$extends} |";
        }

        if (!empty($implements)) {
            $implements = implode(', ', $implements);
            $output .= "
| Implements | {$implements} |";
        }

        $output .= "

{$classComment}
";

        if (count($constants) > 0) {
            $constants = implode(PHP_EOL, $constants);
            $output .= "
## Constants
```php
{$constants}
```
";
        }

        if (count($properties) > 0) {
            $properties = implode(PHP_EOL, $properties);
            $output .= "
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
            $output .= "
## Methods
{$signature}
";
        }

    }

    echo $output;
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
            $return['comment'] = getDocblock($item['value']);
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

            $signature .= ('class' === $type) ? ' Class ' : ' Interface ';
            $signature .= $return['namespace'] .'\\' . $item['name'];
            $return['signature'] = ltrim($signature);

            $return['extends'] = $item['extends'] ?? '';

            $implements = $item['implements'] ?? [];
            if (count($implements) > 0) {
                foreach ($implements as $implement) {
                    $return['implements'][] = $implement['value'];
                }
            }

            $return['constants']  = parseConstants($item['definition']);
            $return['properties'] = parseProperties($item['definition']);
            $return['methods']    = parseMethods($item['definition']);
        }
    }

    return $return;
}

function parseConstants(array $item): array
{
    $constants = $item['constants'] ?? [];
    $return     = [];
    foreach ($constants as $constant) {
        if ('const' === $constant['type']) {
            $signature  = 'const ' . $constant['name'];
            if (isset($constant['default']['value'])) {
                $signature .= ' = ' . $constant['default']['value'];
            }

            $return[] = $signature . ';';
        }
    }

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

        $params = $method['parameters'] ?? [];
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
            $list     = $retType['list'] ?? [];
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
                        $retTypes[] = $li['data-type'];
                    }
                }

                $signature .= ': ' . implode(' | ', $retTypes);
            }
        }

        $return[] = [
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

    foreach ($properties as $property) {
        $line = $property['docblock'] ?? '';
        $line = getDocblock($line);

        $signature  = '';
        $visibility = $property['visibility'] ?? [];
        foreach ($visibility as $vis) {
            $signature .= ' ' . $vis;
        }

        $signature .= ' ' . $property['name'];

        if (isset($property['default']['value'])) {
            $signature .= ' = ' . $property['default']['value'];
        }

        $return[] = $line . PHP_EOL . ltrim($signature) . ';' . PHP_EOL;
    }

    return $return;
}
//    "properties": [
//        {
//            "visibility": [
//            "protected"
//        ],
//          "type": "property",
//          "name": "activeAccess",
//          "docblock": "**\n     * Active access which the list is checking if some role can access it\n     *\n     * @var string\n     *",
//          "shortcuts": [
//            {
//                "type": "shortcut",
//              "name": "get",
//              "file": "(eval code)",
//              "line": 26,
//              "char": 34
//            }
//          ],
//        },


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
    $description = '';
    $lines = explode("\n", trim($source));

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
//    $count = \count($lines);
//
//    foreach ($lines as $i => $line) {
//        $line = preg_replace('#^([\s\t]+)?/?([*]+)([\s\t]+)?$#im', '', rtrim($line));
//        $line = preg_replace('#^([\s\t]+)?([*]+)([\s\t]+)?/?$#im', '', rtrim($line));
//
//        if ((0 === $i || $i === $count - 1) && empty($line)) {
//            continue;
//        }
//
//        $cleaned = trim($line, "\t*\0 ");
//        $cleaned = str_replace('$$', '$', $cleaned);
//
//        if (0 === strpos($cleaned, '@')) {
//            $linesArray[] = $line = $cleaned;
//        } else {
//            $line = preg_replace('#([\s\t]+)?[*]#', '', $line);
//            $line = preg_replace('#([\s\t]+)?[*]([\s\t]){1,2}#', '$1* ', ' * '.$line);
//            $line = preg_replace('#[*]([\s\t])+$#', '*', $line);
//            $line = preg_replace('#\t#', '', $line);
//
//            $linesArray[] = array_pop($linesArray)."\n".$line;
//        }
//    }
//
//    if (!empty($linesArray) && 0 !== strpos(trim($linesArray[0], "\t*\0 "), '@')) {
//        $description = array_shift($linesArray);
//        $description = explode("\n", $description);
//
//        $cleaned = [];
//        $empty = 0;
//        foreach ($description as $i => $line) {
//            if (preg_match('#^([\s\t]+)?[*]([\s\t]+)?$#', $line)) {
//                ++$empty;
//            } else {
//                $empty = 0;
//            }
//
//            if ($empty > 1) {
//                continue;
//            }
//
//            $cleaned[] = $line;
//        }
//
//        $reversed = array_reverse($cleaned);
//        if (empty($reversed[0]) || '' === trim($reversed[0], "\t*\0 ")) {
//            unset($reversed[0]);
//        }
//
//        $description = implode("\n", array_reverse($reversed));
//    }
//
//    $doc = '';
//
//    if (!empty($description)) {
//        $doc = $description;
//    }
//
//    if (!empty($linesArray)) {
//        $lines = array_map(function ($line) use ($indent) {
//            return "$indent * $line";
//        }, $linesArray);
//
//        if (!empty($doc)) {
//            $doc .= "\n$indent *";
//        }
//
//        $doc .= "\n".implode("\n", $lines);
//    }
//
    return '/' . $doc . '/';
//    return '' === $doc ? '' : "/**$doc\n */";
}
