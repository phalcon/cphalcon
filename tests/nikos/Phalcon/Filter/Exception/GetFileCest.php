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

namespace Phalcon\Test\Unit\Filter\Exception;

use UnitTester;

class GetFileCest
{
    /**
     * Tests Phalcon\Filter\Exception :: getFile()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function filterExceptionGetFile(UnitTester $I)
    {
        $I->wantToTest('Filter\Exception - getFile()');

        $I->skipTest('Need implementation');
    }
}
