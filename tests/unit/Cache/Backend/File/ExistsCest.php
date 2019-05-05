<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Cache\Backend\File;

use UnitTester;

class ExistsCest
{
    /**
     * Tests Phalcon\Cache\Backend\File :: exists()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cacheBackendFileExists(UnitTester $I)
    {
        $I->wantToTest('Cache\Backend\File - exists()');

        $I->skipTest('Need implementation');
    }
}
