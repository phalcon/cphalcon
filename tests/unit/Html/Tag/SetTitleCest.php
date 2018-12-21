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

namespace Phalcon\Test\Unit\Html\Tag;

use Phalcon\Html\Tag;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\TagSetupTrait;
use UnitTester;

/**
 * Class SetTitleCest
 *
 * @package Phalcon\Test\Unit\Html\Tag
 */
class SetTitleCest
{
    use DiTrait;
    use TagSetupTrait;

    /**
     * Tests Phalcon\Html\Tag :: setTitle()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function htmlTagSetTitle(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - setTitle()');
        $tag = new Tag();
        $tag->setDI($this->container);

        $value    = 'This is my title';
        $expected = "<title>{$value}</title>" . PHP_EOL;
        $actual   = $tag
            ->setTitle($value)
            ->renderTitle()
        ;
        $I->assertEquals($expected, $actual);

        $expected = "{$value}";
        $actual   = $tag->getTitle();
        $I->assertEquals($expected, $actual);
    }
}
