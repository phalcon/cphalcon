<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Config\Fake\Adapter;

use Phalcon\Config\Adapter\Yaml;

final class FakeYamlParseFile extends Yaml
{
    /**
     * Parse a YAML stream from a file
     *
     * @param string $filename
     * @param int    $pos
     * @param array  $callbacks
     *
     * @return mixed
     *
     * @link https://php.net/manual/en/function.yaml-parse-file.php
     */
    protected static function phpYamlParseFile(
        string $filename,
        int $pos = 0,
        array $callbacks = []
    ): mixed {
        return false;
    }
}
