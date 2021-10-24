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

/**
 * Class ExistsCest
 *
 * @package Phalcon\Tests\Unit\Translate\Adapter\Gettext
 */
class ExistsCest
{
    use TranslateGettextTrait;

    /**
     * Tests Phalcon\Translate\Adapter\Gettext :: exists()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function translateAdapterGettextExists(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\Gettext - exists()');

        $params     = $this->getGettextConfig();
        $translator = new Gettext(new InterpolatorFactory(), $params);

        $actual = $translator->exists('hi');
        $I->assertTrue($actual);
    }
}
