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

namespace Phalcon\Test\Unit\Mvc\Url;

use Phalcon\Mvc\Url;
use UnitTester;

/**
 * Class GetCest
 *
 * @package Phalcon\Test\Unit\Mvc\Url
 */
class GetCest
{
    /**
     * Tests Phalcon\Mvc\Url :: get()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcUrlGet(UnitTester $I)
    {
        $I->wantToTest("Mvc\Url - get()");
        $url = new Url();

        $url->setBaseUri('https://phalconphp.com');

        $expected = 'https://phalconphp.com';
        $actual   = $url->get();
        $I->assertEquals($expected, $actual);

        $actual = $url->get('');
        $I->assertEquals($expected, $actual);

        $expected = 'https://phalconphp.com/';
        $actual   = $url->get('/');
        $I->assertEquals($expected, $actual);

        $expected = 'https://phalconphp.com/en/team';
        $actual   = $url->get('/en/team');
        $I->assertEquals($expected, $actual);
    }
}
