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

namespace Phalcon\Test\Unit\Translate\Adapter\Gettext;

use Phalcon\Test\Fixtures\Traits\TranslateGettextTrait;
use Phalcon\Translate\Adapter\Gettext;
use Phalcon\Translate\InterpolatorFactory;
use UnitTester;

class GetSetDefaultDomainCest
{
    use TranslateGettextTrait;

    /**
     * Tests Phalcon\Translate\Adapter\Gettext ::
     * getDefaultDomain()/setDefaultDomain()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function translateAdapterGettextGetSetDefaultDomain(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\Gettext - getDefaultDomain()/setDefaultDomain()');

        $params     = $this->getGettextConfig();
        $translator = new Gettext(new InterpolatorFactory(), $params);

        $I->assertEquals(
            'messages',
            $translator->getDefaultDomain()
        );

        $translator->setDefaultDomain('options');

        $I->assertEquals(
            'options',
            $translator->getDefaultDomain()
        );
    }
}
