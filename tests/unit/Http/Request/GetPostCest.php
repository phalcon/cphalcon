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

namespace Phalcon\Test\Unit\Http\Request;

use Phalcon\Di;
use Phalcon\Di\FactoryDefault;
use Phalcon\Test\Unit\Http\Helper\HttpBase;
use UnitTester;

/**
 * Class GetPostCest
 */
class GetPostCest //extends HttpBase
{
    /**
     * Tests Phalcon\Http\Request :: getPost()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function httpRequestGetPost(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getPost()');

        $oldPost = $_POST;
        $_POST['test'] = -1234;

        $container = new FactoryDefault();
        Di::reset();
        Di::setDefault($container);

        $request = $container['request'];

//        var_dump($container['filter']); die();

//        $request = $this->getRequestObject();
        $expected = 1234;
        $actual = $request->getPost('test', 'absint');
        $I->assertEquals($expected, $actual);

        $_POST = $oldPost;
    }
}
