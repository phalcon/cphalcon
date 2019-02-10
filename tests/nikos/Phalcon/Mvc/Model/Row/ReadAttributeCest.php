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

namespace Phalcon\Test\Unit\Mvc\Model\Row;

use UnitTester;

/**
 * Class ReadAttributeCest
 */
class ReadAttributeCest
{
    /**
     * Tests Phalcon\Mvc\Model\Row :: readAttribute()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function mvcModelRowReadAttribute(UnitTester $I)
    {
        $I->wantToTest('Mvc\Model\Row - readAttribute()');
        $I->skipTest('Need implementation');
    }
}
