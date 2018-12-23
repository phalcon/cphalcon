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

namespace Phalcon\Test\Unit\Application\Exception;

use UnitTester;

/**
 * Class GetFileCest
 */
class GetFileCest
{
    /**
     * Tests Phalcon\Application\Exception :: getFile()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function applicationExceptionGetFile(UnitTester $I)
    {
        $I->wantToTest('Application\Exception - getFile()');
        $I->skipTest('Need implementation');
    }
}
