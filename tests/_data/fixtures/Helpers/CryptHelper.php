<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Helpers;

use UnitTester;

class CryptHelper
{
    public function _before(UnitTester $I, $scenario)
    {
        if (!extension_loaded('openssl')) {
            $scenario->skip('Warning: openssl extension is not loaded');
        }
    }
}
