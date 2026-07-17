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

use Phalcon\Config\Adapter\Ini;

class FakeIniParseFile extends Ini
{
    /**
     * Parse a configuration file
     *
     * @param string $filename
     * @param bool   $processSections
     * @param int    $scannerMode
     *
     * @return array|false
     *
     * @link https://php.net/manual/en/function.parse-ini-file.php
     */
    protected static function phpParseIniFile(
        string $filename,
        bool $processSections = false,
        int $scannerMode = 0
    ): array|false {
        return false;
    }
}
