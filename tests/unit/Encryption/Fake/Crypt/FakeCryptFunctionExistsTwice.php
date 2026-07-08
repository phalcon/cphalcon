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

namespace Phalcon\Tests\Unit\Encryption\Fake\Crypt;

use Phalcon\Encryption\Crypt;

class FakeCryptFunctionExistsTwice extends Crypt
{
    private static int $usage = 0;

    public function __construct(...$args)
    {
        self::$usage = 0;

        parent::__construct(...$args);
    }

    /**
     * Return true if the given function has been defined
     *
     * @param string $function
     *
     * @return bool
     *
     * @link https://php.net/manual/en/function.function-exists.php
     */
    protected static function phpFunctionExists(string $function): bool
    {
        if (0 === self::$usage) {
            self::$usage++;

            return parent::phpFunctionExists($function);
        }

        return false;
    }
}
