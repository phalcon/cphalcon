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

namespace Phalcon\Tests\Unit\Translate\Adapter\Gettext;

use Phalcon\Tests\Fixtures\Traits\TranslateGettextTrait;
use Phalcon\Translate\Adapter\Gettext;
use Phalcon\Translate\InterpolatorFactory;
use UnitTester;

use const LC_MESSAGES;

/**
 * Class GetCategoryCest
 *
 * @package Phalcon\Tests\Unit\Translate\Adapter\Gettext
 */
class GetCategoryCest
{
    use TranslateGettextTrait;

    /**
     * Tests Phalcon\Translate\Adapter\Gettext :: getCategory()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function translateAdapterGettextGetCategory(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\Gettext - getCategory()');

        $params     = $this->getGettextConfig();
        $translator = new Gettext(new InterpolatorFactory(), $params);

        $actual = $translator->getCategory();
        $I->assertEquals(LC_MESSAGES, $actual);
    }
}
