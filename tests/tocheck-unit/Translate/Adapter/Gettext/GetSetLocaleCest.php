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

namespace Phalcon\Test\Unit\Translate\Adapter\Gettext;

use Phalcon\Test\Fixtures\Traits\TranslateGettextTrait;
use Phalcon\Translate\Adapter\Gettext;
use Phalcon\Translate\InterpolatorFactory;
use UnitTester;

class GetSetLocaleCest
{
    use TranslateGettextTrait;

    /**
     * Tests Phalcon\Translate\Adapter\Gettext :: getLocale()/setLocale()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function translateAdapterGettextGetSetLocale(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\Gettext - getLocale()/setLocale()');

        $params     = $this->getGettextConfig();
        $translator = new Gettext(new InterpolatorFactory(), $params);

        $I->assertEquals(
            'en_US.utf8',
            $translator->getLocale()
        );

        $translator->setLocale(1, 'ru');

        $I->assertEquals(
            '',
            $translator->getLocale()
        );
    }
}
