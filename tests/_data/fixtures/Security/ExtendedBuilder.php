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

namespace Phalcon\Tests\Fixtures\Security;

use Phalcon\Security\JWT\Builder;

/**
 * Class ExtendedBuilder
 *
 * @package Phalcon\Tests\Fixtures\Security
 */
class ExtendedBuilder extends Builder
{
    public function addClaim(string $name, $value): ExtendedBuilder
    {
        return $this->setClaim($name, $value);
    }
}
