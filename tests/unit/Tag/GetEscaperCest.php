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

use Phalcon\Escaper;
use Phalcon\Escaper\EscaperInterface;
use Phalcon\Tag;
use Phalcon\Test\Fixtures\Helpers\TagSetup;
use UnitTester;

class GetEscaperCest extends TagSetup
{
    /**
     * Tests Phalcon\Tag :: getEscaper()
     *
     * @param UnitTester $I
     *
     * @since  2018-11-13
     *
     * @author Phalcon Team <team@phalcon.io>
     */
    public function tagGetEscaper(UnitTester $I)
    {
        $I->wantToTest('Tag - getEscaper()');

        $escaper = Tag::getEscaper([]);
        $I->assertInstanceOf(Escaper::class, $escaper);
        $I->assertInstanceOf(EscaperInterface::class, $escaper);

        $escaper = Tag::getEscaper(["escape" => false]);
        $I->assertNull($escaper);
    }
}
