<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Tag;

use Phalcon\Http\Response;
use Phalcon\Tag;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;

class PreloadCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Tag :: setTitleSeparator()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2012-09-05
     * @since  2018-11-13
     */
    public function tagPreload(UnitTester $I)
    {
        $I->wantToTest('Tag - preload()');

        /**
         * Making sure we have a response object
         */
        $this->setNewFactoryDefault();

        /** @var Response $response */
        $response = $this->container->get('response');
        Tag::setDI($this->container);

        $expected = "abc.css";
        $actual   = Tag::preload(["abc.css"]);
        $I->assertEquals($expected, $actual);

        $expected = [
            'Link: <abc.css>; rel="preload"; as="style"' => null,
        ];
        $actual   = $response->getHeaders()->toArray();
        $I->assertEquals($expected, $actual);

        $expected = "abc.jpg";
        $actual   = Tag::preload(['abc.jpg', ['as' => 'image']]);
        $I->assertEquals($expected, $actual);

        $expected = [
            'Link: <abc.css>; rel="preload"; as="style"' => null,
            'Link: <abc.jpg>; rel="preload"; as="image"' => null,
        ];
        $actual   = $response->getHeaders()->toArray();
        $I->assertEquals($expected, $actual);

        $expected = "abc.css";
        $actual   = Tag::preload(['abc.css', ['as' => 'style', 'nopush' => true]]);
        $I->assertEquals($expected, $actual);

        $expected = [
            'Link: <abc.css>; rel="preload"; as="style"'         => null,
            'Link: <abc.jpg>; rel="preload"; as="image"'         => null,
            'Link: <abc.css>; rel="preload"; as="style"; nopush' => null,
        ];
        $actual   = $response->getHeaders()->toArray();
        $I->assertEquals($expected, $actual);
    }
}
