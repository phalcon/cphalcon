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

namespace Phalcon\Test\Unit\Acl\Subject;

use Phalcon\Acl\Subject;
use UnitTester;

/**
 * Class GetNameCest
 */
class GetNameCest
{
    /**
     * Tests Phalcon\Acl\Subject :: getName()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclSubjectGetName(UnitTester $I)
    {
        $I->wantToTest('Acl\Subject - getName()');
        $subject = new Subject('Customers');

        $expected = 'Customers';
        $actual   = $subject->getName();
        $I->assertEquals($expected, $actual);
    }
}
