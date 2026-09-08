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

namespace Phalcon\Tests\Support\Objects;

/**
 * Fixture for Hydration\GetPrivateProperties: supplies private, protected,
 * public and private static properties, plus a name that the child shadows.
 */
class PrivatePropertiesParent
{
    public $publicParent = null;

    protected $protectedParent = null;

    private $parentOnly = null;

    private $shadowed = 'parent';

    private static $staticParent = null;
}
