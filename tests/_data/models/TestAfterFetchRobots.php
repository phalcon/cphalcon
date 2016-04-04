<?php
/**
 * Created by PhpStorm.
 * User: Wojtek
 * Date: 2016-04-09
 * Time: 23:07
 */

namespace Phalcon\Test\Models;

use DateTime;
use Phalcon\Mvc\Model;

/**
 * \Phalcon\Test\Models\TestAfterFetchRobots.php
 * TestAfterFetchRobots model class
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @author    Wojciech Ślawski <jurigag@gmail.com>
 * @package   Phalcon\Test\Models
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class TestAfterFetchRobots extends Model
{
    public function getSource()
    {
        return 'robots';
    }
    
    public function afterFetch()
    {
        $this->datetime = new DateTime($this->datetime);
        $this->text = "texttexttext";
    }
}
