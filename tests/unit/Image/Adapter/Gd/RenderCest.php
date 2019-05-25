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

namespace Phalcon\Test\Unit\Image\Adapter\Gd;

use Phalcon\Image\Adapter\Gd;
use Phalcon\Test\Fixtures\Traits\GdTrait;
use UnitTester;

class RenderCest
{
    use GdTrait;

    /**
     * Tests Phalcon\Image\Adapter\Gd :: render()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function imageAdapterGdRender(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - render()');

        $params = [
            'jpg' => [130699, '679ce149f0b54b6a5ee6b0f7b476efa8'],
            'png' => [8802, '17909972f73be3698ad96bcd18e043f0'],
        ];

        foreach ($this->getImages() as $type => $imagePath) {
            $image = new Gd(
                $imagePath
            );

            list($lenght, $md5) = $params[$type];

            $I->assertSame($lenght, mb_strlen($image->render()));
            $I->assertSame($md5, md5($image->render()));
        }
    }
}
