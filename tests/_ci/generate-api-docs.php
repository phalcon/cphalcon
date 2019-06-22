<?php
declare(strict_types=1);

$root = dirname(dirname(dirname(__FILE__))) . '/phalcon/';

$documents = [
    [
        'title'  => 'Phalcon\Acl',
        'output' => 'Phalcon_Acl.md',
        'docs'   => [
            '#Acl'                => 'Acl.zep',
            '#Adapter_Memory'     => 'Acl/Adapter/Memory.zep',
//            '#Adapter'            => 'Acl/Adapter.zep',
//            '#AdapterInterface'   => 'Acl/AdapterInterface.zep',
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
        $implements   = $data['implements'] ?? '';
        $constants    = $data['constants'] ?? [];
        $properties   = $data['properties'] ?? [];

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
            $return['comment'] = parseClassDocblock($item['value']);
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

        if ('class' === $type) {
            $signature = '';
            if (1 === $item['final']) {
                $signature .= ' Final';
            };
            if (1 === $item['abstract']) {
                $signature .= ' Abstract';
            };

            $signature .= ' Class ' . $return['namespace'] .'\\' . $item['name'];
            $return['signature'] = ltrim($signature);

            $implements = $item['implements'] ?? [];
            if (count($implements) > 0) {
                foreach ($implements as $implement) {
                    $return['implements'][] = $implement['value'];
                }
            }

            $return['constants']  = parseConstants($item['definition']);
            $return['properties'] = parseProperties($item['definition']);
        }
    }

    return $return;
}

function parseClassDocblock(string $text): string
{
    //"**\n * Manages ACL lists in memory\n *\n *```php\n * $acl = new \\Phalcon\\Acl\\Adapter\\Memory();\n *\n * $acl->setDefaultAction(\n *     \\Phalcon\\Acl::DENY\n * );\n *\n * \/\/ Register roles\n * $roles = [\n *     \"users\"  => new \\Phalcon\\Acl\\Role(\"Users\"),\n *     \"guests\" => new \\Phalcon\\Acl\\Role(\"Guests\"),\n * ];\n * foreach ($roles as $role) {\n *     $acl->addRole($role);\n * }\n *\n * \/\/ Private area components\n * $privateComponents = [\n *     \"companies\" => [\"index\", \"search\", \"new\", \"edit\", \"save\", \"create\", \"delete\"],\n *     \"products\"  => [\"index\", \"search\", \"new\", \"edit\", \"save\", \"create\", \"delete\"],\n *     \"invoices\"  => [\"index\", \"profile\"],\n * ];\n *\n * foreach ($privateComponents as $componentName => $actions) {\n *     $acl->addComponent(\n *         new \\Phalcon\\Acl\\Component($componentName),\n *         $actions\n *     );\n * }\n *\n * \/\/ Public area components\n * $publicComponents = [\n *     \"index\"   => [\"index\"],\n *     \"about\"   => [\"index\"],\n *     \"session\" => [\"index\", \"register\", \"start\", \"end\"],\n *     \"contact\" => [\"index\", \"send\"],\n * ];\n *\n * foreach ($publicComponents as $componentName => $actions) {\n *     $acl->addComponent(\n *         new \\Phalcon\\Acl\\Component($componentName),\n *         $actions\n *     );\n * }\n *\n * \/\/ Grant access to public areas to both users and guests\n * foreach ($roles as $role){\n *     foreach ($publicComponents as $component => $actions) {\n *         $acl->allow($role->getName(), $component, \"*\");\n *     }\n * }\n *\n * \/\/ Grant access to private area to role Users\n * foreach ($privateComponents as $component => $actions) {\n *     foreach ($actions as $action) {\n *         $acl->allow(\"Users\", $component, $action);\n *     }\n * }\n *```\n *",
    return str_replace(
        [
            '**' . PHP_EOL,
            ' * ',
            ' *',
        ],
        [
            '',
            '',
            '',
        ],
        $text
    );
}

function parseDocblock(string $text): string
{
    return str_replace(
        [
            "    *",
        ],
        [
            "*",
        ],
        $text
    );
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

function parseProperties(array $item): array
{
    $properties = $item['properties'] ?? [];
    $return     = [];

    foreach ($properties as $property) {
        $line = $property['docblock'] ?? '';
        $line = parseDocblock($line);

        $signature  = '';
        $visibility = $property['visibility'] ?? [];
        foreach ($visibility as $vis) {
            $signature .= ' ' . $vis;
        }

        $signature .= ' ' . $property['name'];

        if (isset($property['default']['value'])) {
            $signature .= ' = ' . $property['default']['value'];
        }

        $return[] = '/' . $line . '/' . PHP_EOL . ltrim($signature) . ';' . PHP_EOL;
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
//          "file": "(eval code)",
//          "line": 32,
//          "char": 6
//        },
//    {
//        "visibility": [
//        "protected"
//    ],
//          "type": "property",
//          "name": "accessGranted",
//          "default": {
//              "type": "bool",
//              "value": "false",
//          },
//          "docblock": "**\n     * Access Granted\n     *\n     * @var bool\n     *",
//        },

