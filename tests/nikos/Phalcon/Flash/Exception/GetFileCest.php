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

namespace Phalcon\Test\Unit\Flash\Exception;

use UnitTester;

/**
 * Class GetFileCest
 */
class GetFileCest
{
    /**
     * Tests Phalcon\Flash\Exception :: getFile()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function flashExceptionGetFile(UnitTester $I)
    {
        $I->wantToTest('Flash\Exception - getFile()');
        $I->skipTest('Need implementation');
    }
}
