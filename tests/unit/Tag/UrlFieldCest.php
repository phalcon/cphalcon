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

namespace Phalcon\Test\Unit\Tag;

use Phalcon\Tag;
use Phalcon\Test\Fixtures\Helpers\TagHelper;

use UnitTester;

/**
 * Class UrlFieldCest
 *
 * @package Phalcon\Test\Unit\Tag
 */
class UrlFieldCest extends TagHelper
{
    protected $function  = 'urlField';
    protected $inputType = 'url';
}
