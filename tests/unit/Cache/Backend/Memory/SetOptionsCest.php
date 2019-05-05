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

namespace Phalcon\Test\Unit\Cache\Backend\Memory;

use UnitTester;

class SetOptionsCest
{
    /**
     * Tests Phalcon\Cache\Backend\Memory :: setOptions()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cacheBackendMemorySetOptions(UnitTester $I)
    {
        $I->wantToTest('Cache\Backend\Memory - setOptions()');

        $I->skipTest('Need implementation');
    }
}
