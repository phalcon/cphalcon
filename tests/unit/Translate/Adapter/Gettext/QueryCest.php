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

class QueryCest
{
    use TranslateGettextTrait;

    /**
     * Tests Phalcon\Translate\Adapter\Gettext :: query()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function translateAdapterGettextQuery(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\Gettext - query()');

        $params     = $this->getGettextConfig();
        $translator = new Gettext(
            new InterpolatorFactory(),
            $params
        );

        $I->assertEquals('Hello', $translator->query('hi'));

        $I->assertEquals('Hello Jeremy', $translator->query('hello-key', ['name' => 'Jeremy']));

        $aParamQuery = ['song' => 'Phalcon rocks', 'artist' => 'Phalcon team'];

        $sTranslateResult = $translator->query('song-key', $aParamQuery);

        $I->assertEquals('The song is Phalcon rocks (Phalcon team)', $sTranslateResult);
    }
}
