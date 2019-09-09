<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Request;

use Phalcon\Di;
use Phalcon\Di\FactoryDefault;
use UnitTester;

class GetPostCest //extends HttpBase
{
    /**
     * Tests Phalcon\Http\Request :: getPost()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function httpRequestGetPost(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getPost()');

        $oldPost       = $_POST;
        $_POST['test'] = -1234;

        $container = new FactoryDefault();
        Di::reset();
        Di::setDefault($container);

        $request = $container['request'];

//        $request = $this->getRequestObject();

        $I->assertEquals(
            1234,
            $request->getPost('test', 'absint')
        );

        $_POST = $oldPost;
    }
}
