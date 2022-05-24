
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Annotations\Adapter;

use Phalcon\Annotations\Reader;
use Phalcon\Annotations\Exception;
use Phalcon\Annotations\Collection;
use Phalcon\Annotations\Reflection;
use Phalcon\Annotations\ReaderInterface;

/**
 * This is the base class for Phalcon\Annotations adapters
 */
abstract class AbstractAdapter implements AdapterInterface
{
    /**
     * @var array
     */
    protected annotations = [];

    /**
     * @var Reader
     */
    protected reader;

    /**
     * Parses or retrieves all the annotations found in a class
     */
    public function get(var className) -> <Reflection>
    {
        var classAnnotations, parsedAnnotations, realClassName, reader;

        /**
         * Get the class name if it's an object
         */
        if typeof className == "object" {
            let realClassName = get_class(className);
        }  else {
            let realClassName = className;
        }

        if isset this->annotations[realClassName] {
            return this->annotations[realClassName];
        }

        /**
         * Try to read the annotations from the adapter
         */
        let classAnnotations = this->{"read"}(realClassName);

        if classAnnotations === null || classAnnotations === false {
            /**
             * Get the annotations reader
             */
            let reader = this->getReader(),
                parsedAnnotations = reader->parse(realClassName);

            let classAnnotations = new Reflection(parsedAnnotations),
                this->annotations[realClassName] = classAnnotations;
                this->{"write"}(realClassName, classAnnotations);
        }

        return classAnnotations;
    }

    /**
     * Returns the annotations found in a specific constant
     */
    public function getConstant(string className, string constantName) -> <Collection>
    {
        var constants, constant;

        let constants = this->getConstants(className);

        if !fetch constant, constants[constantName] {
            /**
             * Returns a collection anyways
             */
            return new Collection();
        }

        return constant;
    }

    /**
     * Returns the annotations found in all the class' constants
     */
    public function getConstants(string className) -> array
    {
        var classAnnotations;

        /**
         * Get the full annotations from the class
         */
        let classAnnotations = this->get(className);

        return classAnnotations->getConstantsAnnotations();
    }

    /**
     * Returns the annotations found in a specific property
     */
    public function getProperty(string className, string propertyName) -> <Collection>
    {
        var classAnnotations, properties, property;

        /**
         * Get the full annotations from the class
         */
        let classAnnotations = this->get(className);

        let properties = classAnnotations->getPropertiesAnnotations();

        if !fetch property, properties[propertyName] {
            /**
             * Returns a collection anyways
             */
            return new Collection();
        }

        return property;
    }

    /**
     * Returns the annotations found in all the class' properties
     */
    public function getProperties(string className) -> array
    {
        var classAnnotations;

        /**
         * Get the full annotations from the class
         */
        let classAnnotations = this->get(className);

        return classAnnotations->getPropertiesAnnotations();
    }

    /**
     * Returns the annotations found in a specific method
     */
    public function getMethod(string className, string methodName) -> <Collection>
    {
        var classAnnotations, methods, method, methodKey;

        /**
         * Get the full annotations from the class
         */
        let classAnnotations = this->get(className);

        let methods = classAnnotations->getMethodsAnnotations();

        if typeof methods == "array" {
            for methodKey, method in methods {
                if !strcasecmp(methodKey, methodName) {
                    return method;
                }
            }
        }

        /**
         * Returns a collection anyway
         */
        return new Collection();
    }

    /**
     * Returns the annotations found in all the class' methods
     */
    public function getMethods(string className) -> array
    {
        var classAnnotations;

        /**
         * Get the full annotations from the class
         */
        let classAnnotations = this->get(className);

        return classAnnotations->getMethodsAnnotations();
    }

    /**
     * Returns the annotation reader
     */
    public function getReader() -> <ReaderInterface>
    {
        if typeof this->reader != "object" {
            let this->reader = new Reader();
        }

        return this->reader;
    }

    /**
     * Sets the annotations parser
     */
    public function setReader(<ReaderInterface> reader)
    {
        let this->reader = reader;
    }
}
