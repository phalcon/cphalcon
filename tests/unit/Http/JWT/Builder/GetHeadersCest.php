<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Http\JWT\Builder;

use Phalcon\Http\JWT\Builder;
use Phalcon\Http\JWT\Signer\Hmac;
use UnitTester;

class GetHeadersCest
{
    /**
     * Unit Tests Phalcon\Http\JWT\Builder :: getHeaders()
     *
     * @since  2019-12-19
     */
    public function httpJWTBuilderGetHeaders(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Builder - getHeaders()');

        $signer  = new Hmac();
        $builder = new Builder($signer);

        $expected = [
            'alg' => $signer->getAlgHeader(),
            'typ' => 'JWT',
        ];
        $I->assertEquals($expected, $builder->getHeaders());
    }
}
