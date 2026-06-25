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

namespace Phalcon\Tests\Unit\Logger\Fake\Adapter;

use Phalcon\Logger\Adapter\Syslog;

final class FakeSyslogAdapter extends Syslog
{
    /**
     * Open connection to system logger
     *
     * @link https://php.net/manual/en/function.openlog.php
     *
     * @param string $ident
     * @param int    $option
     * @param int    $facility
     *
     * @return bool
     */
    protected function openlog(string $ident, int $option, int $facility): bool
    {
        return false;
    }
}
