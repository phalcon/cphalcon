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

use ArrayAccess;
use Phalcon\Test\Fixtures\Traits\TranslateGettextTrait;
use Phalcon\Translate\Adapter\AdapterInterface;
use Phalcon\Translate\Adapter\Gettext;
use Phalcon\Translate\Exception;
use Phalcon\Translate\InterpolatorFactory;
use UnitTester;

class ConstructCest
{
    use TranslateGettextTrait;

    /**
     * Tests Phalcon\Translate\Adapter\Gettext :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function translateAdapterGettextConstruct(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\Gettext - constructor');

        $params     = $this->getGettextConfig();
        $translator = new Gettext(new InterpolatorFactory(), $params);

        $I->assertInstanceOf(ArrayAccess::class, $translator);
        $I->assertInstanceOf(AdapterInterface::class, $translator);
    }

    /**
     * Tests Phalcon\Translate\Adapter\Gettext :: __construct() - Exception
     *
     * @author Ivan Zubok <chi_no@ukr.net>
     * @since  2014-11-04
     */
    public function translateAdapterGettextContentParamExist(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\Gettext - constructor without "locale" throws exception');

        $I->expectThrowable(
            new Exception("Parameter 'locale' is required"),
            function () {
                new Gettext(
                    new InterpolatorFactory(),
                    []
                );
            }
        );
    }
}
